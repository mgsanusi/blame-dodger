#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <gssrpc/rpc.h>
#include <errno.h>
enum xdr_op { XDR_ENCODE = 0, XDR_DECODE = 1, XDR_FREE = 2 };
typedef int (*xdrprocT) ();
typedef struct XDR {
	enum xdr_op xOp;
	struct xdr_ops {
		int (*xGetlong) (struct XDR *, long *);
		int (*xPutlong) (struct XDR *, long *);
		int (*xGetbytes) (struct XDR *, caddr_t, u_int);
		int (*xPutbytes) (struct XDR *, caddr_t, u_int);
		 u_int(*xGetpostn) (struct XDR *);
		int (*xSetpostn) (struct XDR *, u_int);
		rpc_inline_t *(*xInline) (struct XDR *, int);
		void (*xDestroy) (struct XDR *);
	} *xOps;
	caddr_t xPublic;
	void *xPrivate;
	caddr_t xBase;
	int xHandy;
} xdr;
struct xdr_discrim {
	int val;
	xdrproc_t proc;
};
extern int gssrpcXdrNull(XDR *, void *);
extern int gssrpcXdrInt(XDR *, int *);
extern int gssrpcXdrUInt(XDR *, u_int *);
extern int gssrpcXdrLong(XDR *, long *);
extern int gssrpcXdrULong(XDR *, u_long *);
extern int gssrpcXdrShort(XDR *, short *);
extern int gssrpcXdrUShort(XDR *, u_short *);
extern int gssrpcXdrBool(XDR *, int *);
extern int gssrpcXdrEnum(XDR *, int *);
extern int gssrpcXdrArray(XDR *, caddr_t *, u_int *, u_int, u_int, xdrproc_t);
extern int gssrpcXdrByte(XDR *, char **, u_int *, u_int);
extern int gssrpcXdrOpaque(XDR *, caddr_t, u_int);
extern int gssrpcXdrStr(XDR *, char **, u_int);
extern int gssrpcXdrUnion(XDR *, int *, char *, struct xdr_discrim *,
			  xdrproc_t);
extern int gssrpcXdrCh(XDR *, char *);
extern int gssrpcXdrUCh(XDR *, u_char *);
extern int gssrpcXdrVector(XDR *, char *, u_int, u_int, xdrproc_t);
extern int gssrpcXdrFloat(XDR *, float *);
extern int gssrpcXdrDouble(XDR *, double *);
extern int gssrpcXdrAddress(XDR *, caddr_t *, u_int, xdrproc_t);
extern int gssrpcXdrPointer(XDR *, char **, u_int, xdrproc_t);
extern int gssrpcXdrWrapstring(XDR *, char **);
extern unsigned long gssrpcXdrSizeof(xdrproc_t, void *);
struct netobj {
	u_int nLength;
	char *nByte;
};
typedef struct netobj netobj;
extern int gssrpcXdrNetobj(XDR *, struct netobj *);
extern int gssrpcXdrInt32(XDR *, int32_t *);
extern int gssrpcXdrUInt32(XDR *, uint32_t *);
extern void gssrpcXdrallocMake(XDR *, enum xdr_op);
extern void gssrpcXdrallocFree(XDR *);
extern caddr_t gssrpcXdrallocGetdata(XDR *);
extern void gssrpcXdrmemMake(XDR *, caddr_t, u_int, enum xdr_op);
extern void gssrpcXdrstdioMake(XDR *, FILE *, enum xdr_op);
extern void gssrpcXdrrecMake(XDR * xdrs, u_int, u_int, caddr_t,
			     int (*)(caddr_t, caddr_t, int), int (*)(caddr_t,
								     caddr_t,
								     int));
extern int gssrpcXdrrecEndofrecord(XDR *, int);
extern int gssrpcXdrrecSkiprecord(XDR * xdrs);
extern int gssrpcXdrrecEof(XDR * xdrs);
extern void gssrpcXdrFree(xdrproc_t, void *);
enum auth_stat { AUTH_OK = 0, AUTH_BADCRED = 1, AUTH_REJECTEDCRED =
	    2, AUTH_BADVERF = 3, AUTH_REJECTEDVERF = 4, AUTH_TOOWEAK =
	    5, AUTH_INVALIDRESP = 6, AUTH_FAILED = 7, RPCSEC_GSS_CREDPROBLEM =
	    13, RPCSEC_GSS_CTXPROBLEM = 14 };
union des_block {
	char msg[8];
};
typedef union des_block desBlock;
extern int gssrpcXdrDesBlock(XDR *, des_block *);
struct opaque_auth {
	int oaFlavor;
	caddr_t oaRoot;
	u_int oaLen;
};
struct rpc_msg;
typedef struct AUTH {
	struct opaque_auth ahCred;
	struct opaque_auth ahVerf;
	union des_block ahKey;
	struct auth_ops {
		void (*ahNextverf) (struct AUTH *);
		int (*ahMarshal) (struct AUTH *, XDR *);
		int (*ahValidate) (struct AUTH *, struct opaque_auth *);
		int (*ahRefresh) (struct AUTH *, struct rpc_msg *);
		void (*ahDestroy) (struct AUTH *);
		int (*ahWrap) (struct AUTH *, XDR *, xdrproc_t, caddr_t);
		int (*ahUnwrap) (struct AUTH *, XDR *, xdrproc_t, caddr_t);
	} *ahOps;
	void *ahPrivate;
} auth;
extern AUTH *gssrpcAuthunixMake(char *machname, int uid, int gid, int length,
				int *aupGids);
extern AUTH *gssrpcAuthunixProduceDefault(void);
extern AUTH *gssrpcAuthnoneMake(void);
extern AUTH *gssrpcAuthdesProduce();
extern int gssrpcXdrOpaqueAuth(XDR *, struct opaque_auth *);
enum clnt_stat { RPC_SUCCESS = 0, RPC_CANTENCODEARGS = 1, RPC_CANTDECODERES =
	    2, RPC_CANTSEND = 3, RPC_CANTRECV = 4, RPC_TIMEDOUT =
	    5, RPC_VERSMISMATCH = 6, RPC_AUTHERROR = 7, RPC_PROGUNAVAIL =
	    8, RPC_PROGVERSMISMATCH = 9, RPC_PROCUNAVAIL =
	    10, RPC_CANTDECODEARGS = 11, RPC_SYSTEMERROR = 12, RPC_UNKNOWNHOST =
	    13, RPC_UNKNOWNPROTO = 17, RPC_PMAPFAILURE =
	    14, RPC_PROGNOTREGISTERED = 15, RPC_FAILED = 16 };
struct rpc_err {
	enum clnt_stat reStatus;
	union {
		int reErrno;
		enum auth_stat reWhy;
		struct {
			rpcvers_t low;
			rpcvers_t high;
		} reVers;
		struct {
			int32_t e;
			int32_t t;
		} reLb;
	} yy1;
};
typedef struct CLIENT {
	AUTH *clAuth;
	struct clnt_ops {
		enum clnt_stat (*clName) (struct CLIENT *, rpcproc_t, xdrproc_t,
					  void *, xdrproc_t, void *,
					  struct timeval);
		void (*clAbort) (struct CLIENT *);
		void (*clGeterr) (struct CLIENT *, struct rpc_err *);
		int (*clFreeres) (struct CLIENT *, xdrproc_t, void *);
		void (*clDestroy) (struct CLIENT *);
		int (*clControl) (struct CLIENT *, int, void *);
	} *clOps;
	void *clPrivate;
} client;
extern CLIENT *gssrpcClntrawProduce(rpcprog_t, rpcvers_t);
extern CLIENT *gssrpcClntMake(char *, rpcprog_t, rpcvers_t, char *);
extern CLIENT *gssrpcClnttcpProduce(struct sockaddr_in *, rpcprog_t, rpcvers_t,
				    int *, u_int, u_int);
extern CLIENT *gssrpcClntudpMake(struct sockaddr_in *, rpcprog_t, rpcvers_t,
				 struct timeval, int *);
extern CLIENT *gssrpcClntudpBufcreate(struct sockaddr_in *, rpcprog_t,
				      rpcvers_t, struct timeval, int *, u_int,
				      u_int);
void gssrpcClntPcreateerror(char *);
char *gssrpcClntSpcreateerror(char *);
void gssrpcClntPerrno(enum clnt_stat);
void gssrpcClntPerror(CLIENT *, char *);
char *gssrpcClntSperror(CLIENT *, char *);
struct gssrpc_rpc_createrr {
	enum clnt_stat cfStat;
	struct rpc_err cfError;
};
extern struct gssrpc_rpc_createrr gssrpcRpcCreaterr;
char *gssrpcClntSperrno(enum clnt_stat num);
enum msg_type { CALL = 0, REPLY = 1 };
enum reply_stat { MSG_ACCEPTED = 0, MSG_DENIED = 1 };
enum accept_stat { SUCCESS = 0, PROG_UNAVAIL = 1, PROG_MISMATCH =
	    2, PROC_UNAVAIL = 3, GARBAGE_ARGS = 4, SYSTEM_ERR = 5 };
enum reject_stat { RPC_MISMATCH = 0, AUTH_ERROR = 1 };
struct accepted_reply {
	struct opaque_auth arVerf;
	enum accept_stat arStat;
	union {
		struct {
			rpcvers_t low;
			rpcvers_t high;
		} arVersion;
		struct {
			caddr_t where;
			xdrproc_t proc;
		} arResult;
	} yy1;
};
struct rejected_reply {
	enum reject_stat rjStat;
	union {
		struct {
			rpcvers_t low;
			rpcvers_t high;
		} rjVersion;
		enum auth_stat rjWhy;
	} yy1;
};
struct reply_body {
	enum reply_stat rpStat;
	union {
		struct accepted_reply rpAr;
		struct rejected_reply rpDr;
	} yy1;
};
struct call_body {
	rpcvers_t cbRpcvers;
	rpcprog_t cbProg;
	rpcvers_t cbVers;
	rpcproc_t cbProc;
	struct opaque_auth cbCred;
	struct opaque_auth cbVerf;
};
struct rpc_msg {
	uint32_t rmXid;
	enum msg_type rmDirection;
	union {
		struct call_body rmCmb;
		struct reply_body rmRmb;
	} yy1;
};
extern int gssrpcXdrCallmsg(XDR *, struct rpc_msg *);
extern int gssrpcXdrCallhdr(XDR *, struct rpc_msg *);
extern int gssrpcXdrReplymsg(XDR *, struct rpc_msg *);
extern void gssrpcSeterrAnswer(struct rpc_msg *, struct rpc_err *);
extern int gssrpcXdrAcceptAnswer(XDR *, struct accepted_reply *);
extern int gssrpcXdrRejectAnswer(XDR *, struct rejected_reply *);
struct authunix_parms {
	uint32_t aupTime;
	char *aupMachname;
	int aupUid;
	int aupGid;
	u_int aupLength;
	int *aupGids;
};
extern int gssrpcXdrAuthunixParms(XDR *, struct authunix_parms *);
struct short_hand_verf {
	struct opaque_auth newCred;
};
struct gss_name_struct;
typedef struct gss_name_struct *gssNameT;
struct gss_cred_id_struct;
typedef struct gss_cred_id_struct *gssCredIdT;
struct gss_ctx_id_struct;
typedef struct gss_ctx_id_struct *gCtxIdT;
typedef uint32_t gssUint32;
typedef int32_t gssInt32;
typedef gss_uint32 omUint32;
typedef struct gss_OID_desc_struct {
	OM_uint32 length;
	void *elements;
} gssOidDesc;
typedef struct gss_OID_desc_struct {
	OM_uint32 length;
	void *elements;
} *gssOid;
typedef struct gss_OID_set_desc_struct {
	size_t count;
	gss_OID elements;
} gOidSetDesc;
typedef struct gss_OID_set_desc_struct {
	size_t count;
	gss_OID elements;
} *gssOidSet;
typedef struct gss_buffer_desc_struct {
	size_t length;
	void *val;
} gBuffDesc;
typedef struct gss_buffer_desc_struct {
	size_t length;
	void *val;
} *gBufT;
typedef struct gss_channel_bindings_struct {
	OM_uint32 initiatorAddrtype;
	gss_buffer_desc initiatorAddress;
	OM_uint32 acceptorAddrtype;
	gss_buffer_desc acceptorAddress;
	gss_buffer_desc applicationData;
} *gssChannelBindingsT;
typedef OM_uint32 gQopT;
typedef int gCredUseT;
extern gss_OID gssCNtUserName;
extern gss_OID gssCNtMachineUidName;
extern gss_OID gCNtStrUidName;
extern gss_OID gssCNtHostbasedServiceX;
extern gss_OID gssCNtHostbasedService;
extern gss_OID gssCNtAnonymous;
extern gss_OID gCNtExportName;
OM_uint32 gssAcquireCred(OM_uint32 *, gss_name_t, OM_uint32, gss_OID_set,
			 gss_cred_usage_t, gss_cred_id_t *, gss_OID_set *,
			 OM_uint32 *);
OM_uint32 gssReleaseCred(OM_uint32 *, gss_cred_id_t *);
OM_uint32 gInitSecContext(OM_uint32 *, gss_cred_id_t, gss_ctx_id_t *,
			  gss_name_t, gss_OID, OM_uint32, OM_uint32,
			  gss_channel_bindings_t, gss_buffer_t, gss_OID *,
			  gss_buffer_t, OM_uint32 *, OM_uint32 *);
OM_uint32 gssAcceptSecContext(OM_uint32 *, gss_ctx_id_t *, gss_cred_id_t,
			      gss_buffer_t, gss_channel_bindings_t,
			      gss_name_t *, gss_OID *, gss_buffer_t,
			      OM_uint32 *, OM_uint32 *, gss_cred_id_t *);
OM_uint32 gProcessContextToken(OM_uint32 *, gss_ctx_id_t, gss_buffer_t);
OM_uint32 gDeleteSecContext(OM_uint32 *, gss_ctx_id_t *, gss_buffer_t);
OM_uint32 gContextTime(OM_uint32 *, gss_ctx_id_t, OM_uint32 *);
OM_uint32 gGetMic(OM_uint32 *, gss_ctx_id_t, gss_qop_t, gss_buffer_t,
		  gss_buffer_t);
OM_uint32 gssVerifyMic(OM_uint32 *, gss_ctx_id_t, gss_buffer_t, gss_buffer_t,
		       gss_qop_t *);
OM_uint32 gWrap(OM_uint32 *, gss_ctx_id_t, int, gss_qop_t, gss_buffer_t, int *,
		gss_buffer_t);
OM_uint32 gUnwrap(OM_uint32 *, gss_ctx_id_t, gss_buffer_t, gss_buffer_t, int *,
		  gss_qop_t *);
OM_uint32 gssDisplayStatus(OM_uint32 *, OM_uint32, int, gss_OID, OM_uint32 *,
			   gss_buffer_t);
OM_uint32 gIndicateMechs(OM_uint32 *, gss_OID_set *);
OM_uint32 gCompareName(OM_uint32 *, gss_name_t, gss_name_t, int *);
OM_uint32 gssDisplayName(OM_uint32 *, gss_name_t, gss_buffer_t, gss_OID *);
OM_uint32 gImportName(OM_uint32 *, gss_buffer_t, gss_OID, gss_name_t *);
OM_uint32 gReleaseName(OM_uint32 *, gss_name_t *);
OM_uint32 gssFreeBuff(OM_uint32 *, gss_buffer_t);
OM_uint32 gTurnOidSet(OM_uint32 *, gss_OID_set *);
OM_uint32 gInquireCred(OM_uint32 *, gss_cred_id_t, gss_name_t *, OM_uint32 *,
		       gss_cred_usage_t *, gss_OID_set *);
OM_uint32 gInquireContext(OM_uint32 *, gss_ctx_id_t, gss_name_t *, gss_name_t *,
			  OM_uint32 *, gss_OID *, OM_uint32 *, int *, int *);
OM_uint32 gssWrapSizeLimit(OM_uint32 *, gss_ctx_id_t, int, gss_qop_t, OM_uint32,
			   OM_uint32 *);
OM_uint32 gImportNameObject(OM_uint32 *, void *, gss_OID, gss_name_t *);
OM_uint32 gExportNameObject(OM_uint32 *, gss_name_t, gss_OID, void **);
OM_uint32 gssAddCred(OM_uint32 *, gss_cred_id_t, gss_name_t, gss_OID,
		     gss_cred_usage_t, OM_uint32, OM_uint32, gss_cred_id_t *,
		     gss_OID_set *, OM_uint32 *, OM_uint32 *);
OM_uint32 gInquireCredByMech(OM_uint32 *, gss_cred_id_t, gss_OID, gss_name_t *,
			     OM_uint32 *, OM_uint32 *, gss_cred_usage_t *);
OM_uint32 gExportSecContext(OM_uint32 *, gss_ctx_id_t *, gss_buffer_t);
OM_uint32 gssImportSecondContext(OM_uint32 *, gss_buffer_t, gss_ctx_id_t *);
OM_uint32 gFreeOid(OM_uint32 *, gss_OID *);
OM_uint32 gssMakeEmptyOidSet(OM_uint32 *, gss_OID_set *);
OM_uint32 gLendOidSetMember(OM_uint32 *, gss_OID, gss_OID_set *);
OM_uint32 gTestOidSetMember(OM_uint32 *, gss_OID, gss_OID_set, int *);
OM_uint32 gStringToOid(OM_uint32 *, gss_buffer_t, gss_OID *);
OM_uint32 gssOidToStr(OM_uint32 *, gss_OID, gss_buffer_t);
OM_uint32 gInquireNameForMech(OM_uint32 *, gss_OID, gss_OID_set *);
OM_uint32 gssInquireMechsForName(OM_uint32 *, const gss_name_t, gss_OID_set *);
OM_uint32 gSign(OM_uint32 *, gss_ctx_id_t, int, gss_buffer_t, gss_buffer_t);
OM_uint32 gVerify(OM_uint32 *, gss_ctx_id_t, gss_buffer_t, gss_buffer_t, int *);
OM_uint32 gSeal(OM_uint32 *, gss_ctx_id_t, int, int, gss_buffer_t, int *,
		gss_buffer_t);
OM_uint32 gssUnseal(OM_uint32 *, gss_ctx_id_t, gss_buffer_t, gss_buffer_t,
		    int *, int *);
OM_uint32 gExportName(OM_uint32 *, const gss_name_t, gss_buffer_t);
OM_uint32 gssExtraName(OM_uint32 *, const gss_name_t, gss_name_t *);
OM_uint32 gssCanonicalizeName(OM_uint32 *, const gss_name_t, const gss_OID,
			      gss_name_t *);
OM_uint32 gPseudoRandom(OM_uint32 *, gss_ctx_id_t, int, const gss_buffer_t,
			ssize_t, gss_buffer_t);
OM_uint32 gStoreCred(OM_uint32 *, const gss_cred_id_t, gss_cred_usage_t,
		     const gss_OID, OM_uint32, OM_uint32, gss_OID_set *,
		     gss_cred_usage_t *);
OM_uint32 gSetNegMechs(OM_uint32 *, gss_cred_id_t, const gss_OID_set);
typedef const gss_buffer_desc *gConstBuffT;
typedef const struct gss_channel_bindings_struct *gssConstChannelBindingsT;
typedef const struct gss_ctx_id_struct *gssConstCtxIdT;
typedef const struct gss_cred_id_struct *gConstCredIdT;
typedef const struct gss_name_struct *gConstListT;
typedef const gss_OID_desc *gssConstOid;
typedef const gss_OID_set_desc *gssConstOidSet;
OM_uint32 gIndicateMechsByAttrs(OM_uint32 *, gss_const_OID_set,
				gss_const_OID_set, gss_const_OID_set,
				gss_OID_set *);
OM_uint32 gInquireAttrsForMech(OM_uint32 *, gss_const_OID, gss_OID_set *,
			       gss_OID_set *);
OM_uint32 gDisplayMechAttr(OM_uint32 *, gss_const_OID, gss_buffer_t,
			   gss_buffer_t, gss_buffer_t);
extern gss_const_OID gCMaMechConcrete;
extern gss_const_OID gssCMaMechPseudo;
extern gss_const_OID gssCMaMechComposite;
extern gss_const_OID gssCMaMechNego;
extern gss_const_OID gssCMaMechGlue;
extern gss_const_OID gCMaNotMech;
extern gss_const_OID gssCMaDeprecated;
extern gss_const_OID gCMaNotDfltMech;
extern gss_const_OID gCMaItokFramed;
extern gss_const_OID gCMaAuthInit;
extern gss_const_OID gssCMaAuthTarg;
extern gss_const_OID gssCMaAuthInitInit;
extern gss_const_OID gCMaAuthTargInit;
extern gss_const_OID gCMaAuthInitAnon;
extern gss_const_OID gssCMaAuthTargAnon;
extern gss_const_OID gCMaDelegCred;
extern gss_const_OID gCMaIntegProt;
extern gss_const_OID gCMaConfProt;
extern gss_const_OID gCMaMic;
extern gss_const_OID gssCMaWrap;
extern gss_const_OID gCMaProtReady;
extern gss_const_OID gCMaReplayDet;
extern gss_const_OID gssCMaOosDet;
extern gss_const_OID gCMaCbindings;
extern gss_const_OID gssCMaPfs;
extern gss_const_OID gssCMaCompress;
extern gss_const_OID gCMaCtxTrans;
OM_uint32 gssInquireSaslnameForMech(OM_uint32 *, const gss_OID, gss_buffer_t,
				    gss_buffer_t, gss_buffer_t);
OM_uint32 gInquireMechForSaslname(OM_uint32 *, const gss_buffer_t, gss_OID *);
typedef enum { RPCSEC_GSS_DATA = 0, RPCSEC_GSS_INIT =
	    1, RPCSEC_GSS_CONTINUE_INIT = 2, RPCSEC_GSS_DESTROY =
	    3 } rpcGssProcT;
typedef enum { RPCSEC_GSS_SVC_NONE = 1, RPCSEC_GSS_SVC_INTEGRITY =
	    2, RPCSEC_GSS_SVC_PRIVACY = 3 } rpcGssSvcT;
struct rpc_gss_sec {
	gss_OID mech;
	gss_qop_t qop;
	rpc_gss_svc_t svc;
	gss_cred_id_t cred;
	uint32_t reqFlag;
};
struct authgss_private_data {
	gss_ctx_id_t pdCtx;
	gss_buffer_desc pdCtxHndl;
	uint32_t pdSeqWin;
};
struct rpc_gss_cred {
	u_int gcV;
	rpc_gss_proc_t gcProc;
	uint32_t gcSeq;
	rpc_gss_svc_t gcSvc;
	gss_buffer_desc gcCtx;
};
struct rpc_gss_init_res {
	gss_buffer_desc grCtx;
	uint32_t grMajor;
	uint32_t grMinor;
	uint32_t grWin;
	gss_buffer_desc grToken;
};
int gssrpcXdrRpcGBuff(XDR * xdrs, gss_buffer_t, u_int maxsize);
int gssrpcXdrRpcGCred(XDR * xdrs, struct rpc_gss_cred *k);
int gssrpcXdrRpcGssInitArgs(XDR * xdrs, gss_buffer_desc * k);
int gssrpcXdrRpcGInitRes(XDR * xdrs, struct rpc_gss_init_res *k);
int gssrpcXdrRpcGssData(XDR * xdrs, xdrproc_t xdrFunc, caddr_t xdrPointer,
			gss_ctx_id_t ctx, gss_qop_t qop, rpc_gss_svc_t svc,
			uint32_t seq);
int gssrpcXdrRpcGWrapData(XDR * xdrs, xdrproc_t xdrFunc, caddr_t xdrPointer,
			  gss_ctx_id_t ctx, gss_qop_t qop, rpc_gss_svc_t svc,
			  uint32_t seq);
int gssrpcXdrRpcGUnwrapData(XDR * xdrs, xdrproc_t xdrFunc, caddr_t xdrPointer,
			    gss_ctx_id_t ctx, gss_qop_t qop, rpc_gss_svc_t svc,
			    uint32_t seq);
AUTH *gssrpcAuthgssMake(CLIENT *, gss_name_t, struct rpc_gss_sec *);
AUTH *gssrpcAuthgssProduceDefault(CLIENT *, char *, struct rpc_gss_sec *);
int gssrpcAuthgssService(AUTH * auth, int svc);
int gssrpcAuthgssGetPrivateData(AUTH * auth, struct authgss_private_data *);
struct svc_req;
typedef struct SVCAUTH {
	struct svc_auth_ops {
		int (*svcAhWrap) (struct SVCAUTH *, XDR *, xdrproc_t, caddr_t);
		int (*svcAhUnwrap) (struct SVCAUTH *, XDR *, xdrproc_t,
				    caddr_t);
		int (*svcAhDestroy) (struct SVCAUTH *);
	} *svcAhOps;
	void *svcAhPrivate;
} svcauth;
char *gssrpcSvcauthGssGetStar(SVCAUTH * auth);
int gssrpcSvcauthGSetSvcName(gss_name_t name);
enum xprt_stat { XPRT_DIED, XPRT_MOREREQS, XPRT_IDLE };
typedef struct SVCXPRT {
	int xpSock;
	u_short xpPort;
	struct xp_ops {
		int (*xpRecv) (struct SVCXPRT *, struct rpc_msg *);
		enum xprt_stat (*xpStat) (struct SVCXPRT *);
		int (*xpGetargs) (struct SVCXPRT *, xdrproc_t, void *);
		int (*xpAnswer) (struct SVCXPRT *, struct rpc_msg *);
		int (*xpFreeargs) (struct SVCXPRT *, xdrproc_t, void *);
		void (*xpDestroy) (struct SVCXPRT *);
	} *xpOps;
	int xpAddrlen;
	struct sockaddr_in xpRaddr;
	struct opaque_auth xpVerf;
	SVCAUTH *xpAuth;
	void *xpP1;
	void *xpP2;
	int xpLaddrlen;
	struct sockaddr_in xpLaddr;
} svcxprt;
struct svc_req {
	rpcprog_t rqProg;
	rpcvers_t rqVers;
	rpcproc_t rqProc;
	struct opaque_auth rqCred;
	void *rqClntcred;
	void *rqSvccred;
	void *rqClntname;
	SVCXPRT *rqXprt;
};
extern int gssrpcSvcRead(SVCXPRT *, rpcprog_t, rpcvers_t,
			 void (*)(struct svc_req *, SVCXPRT *), int);
extern int gssrpcRegisterrpc(rpcprog_t, rpcvers_t, rpcproc_t, char *(*)(void *),
			     xdrproc_t, xdrproc_t);
extern void gssrpcSvcUnregister(rpcprog_t, rpcvers_t);
extern void gssrpcXprtRead(SVCXPRT *);
extern void gssrpcXprtUnregister(SVCXPRT *);
extern int gssrpcSvcSendreply(SVCXPRT *, xdrproc_t, caddr_t);
extern void gssrpcSvcerrDecode(SVCXPRT *);
extern void gssrpcSvcerrWeakauth(SVCXPRT *);
extern void gssrpcSvcerrNoproc(SVCXPRT *);
extern void gssrpcSvcerrProgvers(SVCXPRT *, rpcvers_t, rpcvers_t);
extern void gssrpcSvcerrAuth(SVCXPRT *, enum auth_stat);
extern void gssrpcSvcerrNoprog(SVCXPRT *);
extern void gssrpcSvcerrSystemerr(SVCXPRT *);
extern int gssrpcSvcMaxfd;
extern int gssrpcSvcFds;
extern int gssrpcSvcMaxfd;
extern void gssrpcRpctestService();
extern void gssrpcSvcGetreq(int);
extern void gssrpcSvcGetreqset(int *);
extern void gssrpcSvcRun(void);
extern SVCXPRT *gssrpcSvcrawProduce(void);
extern SVCXPRT *gssrpcSvcudpMake(int);
extern SVCXPRT *gssrpcSvcudpBufcreate(int, u_int, u_int);
extern int gssrpcSvcudpEnablecache(SVCXPRT *, uint32_t);
extern SVCXPRT *gssrpcSvctcpProduce(int, u_int, u_int);
extern SVCXPRT *gssrpcSvcfdProduce(int, u_int, u_int);
extern int gssrpcGetMyaddress(struct sockaddr_in *);
extern int gssrpcBindresvport(int, struct sockaddr_in *);
extern int gssrpcBindresvportSa(int, struct sockaddr *);
extern int gssrpcCallrpc(char *, rpcprog_t, rpcvers_t, rpcproc_t, xdrproc_t,
			 char *, xdrproc_t, char *);
extern int gssrpcGetrpcport(char *, rpcprog_t, rpcvers_t, rpcprot_t);
extern int gssrpcRpcDtablesize(void);
int gssrpcBindresvport(int sd, struct sockaddr_in *sockin)
{
	int res;
	static short port;
	struct sockaddr_in myaddr;
	int i;
	if (sockin == ((struct sockaddr_in *)0)) {
		sockin = &myaddr;
		memset(sockin, 0, sizeof(*sockin));
		sockin->sin_family = AF_INET;
	} else if (sockin->sin_family != AF_INET) {
		errno = EPFNOSUPPORT;
		return -1;
	}
	if (port == 0) {
		port = (getpid() % (((IPPORT_RESERVED - 1) - 600) + 1)) + 600;
	}
	res = -1;
	errno = EADDRINUSE;
	for (i = 0;
	     ((i < (((IPPORT_RESERVED - 1) - 600) + 1)) && (res < 0))
	     && (errno == EADDRINUSE); i++) {
		sockin->sin_port = htons(port++);
		if (port > (IPPORT_RESERVED - 1)) {
			port = 600;
		}
		res =
		    bind(sd, (struct sockaddr *)sockin,
			 sizeof(struct sockaddr_in));
	}
	return res;
}
