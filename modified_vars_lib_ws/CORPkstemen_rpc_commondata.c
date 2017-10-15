#include <gssrpc/rpc.h>
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
    int value;
    xdrproc_t proc;
};
extern int gssrpcXdrVoid(XDR *, void *);
extern int gssrpcXdrInt(XDR *, int *);
extern int gssrpcXdrUInt(XDR *, u_int *);
extern int gssrpcXdrLong(XDR *, long *);
extern int gssrpcXdrULong(XDR *, u_long *);
extern int gssrpcXdrShort(XDR *, short *);
extern int gssrpcXdrUShort(XDR *, u_short *);
extern int gssrpcXdrBool(XDR *, int *);
extern int gssrpcXdrEnum(XDR *, int *);
extern int gssrpcXdrArr(XDR *, caddr_t *, u_int *, u_int, u_int,
			xdrproc_t);
extern int gssrpcXdrByte(XDR *, char **, u_int *, u_int);
extern int gssrpcXdrOpaque(XDR *, caddr_t, u_int);
extern int gssrpcXdrString(XDR *, char **, u_int);
extern int gssrpcXdrUnion(XDR *, int *, char *, struct xdr_discrim *,
			  xdrproc_t);
extern int gssrpcXdrCh(XDR *, char *);
extern int gssrpcXdrUCharacter(XDR *, u_char *);
extern int gssrpcXdrVector(XDR *, char *, u_int, u_int, xdrproc_t);
extern int gssrpcXdrFloat(XDR *, float *);
extern int gssrpcXdrDouble(XDR *, double *);
extern int gssrpcXdrAddress(XDR *, caddr_t *, u_int, xdrproc_t);
extern int gssrpcXdrPtr(XDR *, char **, u_int, xdrproc_t);
extern int gssrpcXdrWrapstring(XDR *, char **);
extern unsigned long gssrpcXdrSizeof(xdrproc_t, void *);
struct netobj {
    u_int nLen;
    char *nByte;
};
typedef struct netobj netobj;
extern int gssrpcXdrNetobj(XDR *, struct netobj *);
extern int gssrpcXdrInt32(XDR *, int32_t *);
extern int gssrpcXdrUInt32(XDR *, uint32_t *);
extern void gssrpcXdrallocProduce(XDR *, enum xdr_op);
extern void gssrpcXdrallocTurn(XDR *);
extern caddr_t gssrpcXdrallocGetdata(XDR *);
extern void gssrpcXdrmemMake(XDR *, caddr_t, u_int, enum xdr_op);
extern void gssrpcXdrstdioProduce(XDR *, FILE *, enum xdr_op);
extern void gssrpcXdrrecProduce(XDR * xdrs, u_int, u_int, caddr_t,
				int (*)(caddr_t, caddr_t, int),
				int (*)(caddr_t, caddr_t, int));
extern int gssrpcXdrrecEndofrecord(XDR *, int);
extern int gssrpcXdrrecSkiprecord(XDR * xdrs);
extern int gssrpcXdrrecEof(XDR * xdrs);
extern void gssrpcXdrFree(xdrproc_t, void *);
enum auth_stat { AUTH_OK = 0, AUTH_BADCRED = 1, AUTH_REJECTEDCRED =
	2, AUTH_BADVERF = 3, AUTH_REJECTEDVERF = 4, AUTH_TOOWEAK =
	5, AUTH_INVALIDRESP = 6, AUTH_FAILED = 7, RPCSEC_GSS_CREDPROBLEM =
	13, RPCSEC_GSS_CTXPROBLEM = 14 };
union des_block {
    char c[8];
};
typedef union des_block desBlock;
extern int gssrpcXdrDesBlock(XDR *, des_block *);
struct opaque_auth {
    int oaFlavor;
    caddr_t oaBase;
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
extern AUTH *gssrpcAuthunixMake(char *machname, int uid, int gid,
				int length, int *aupGids);
extern AUTH *gssrpcAuthunixMakeDefault(void);
extern AUTH *gssrpcAuthnoneProduce(void);
extern AUTH *gssrpcAuthdesMake();
extern int gssrpcXdrOpaqueAuth(XDR *, struct opaque_auth *);
enum clnt_stat { RPC_SUCCESS = 0, RPC_CANTENCODEARGS =
	1, RPC_CANTDECODERES = 2, RPC_CANTSEND = 3, RPC_CANTRECV =
	4, RPC_TIMEDOUT = 5, RPC_VERSMISMATCH = 6, RPC_AUTHERROR =
	7, RPC_PROGUNAVAIL = 8, RPC_PROGVERSMISMATCH = 9, RPC_PROCUNAVAIL =
	10, RPC_CANTDECODEARGS = 11, RPC_SYSTEMERROR =
	12, RPC_UNKNOWNHOST = 13, RPC_UNKNOWNPROTO = 17, RPC_PMAPFAILURE =
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
	    int32_t t;
	    int32_t x;
	} reLb;
    } cur;
};
typedef struct CLIENT {
    AUTH *clAuth;
    struct clnt_ops {
	enum clnt_stat (*clCall) (struct CLIENT *, rpcproc_t, xdrproc_t,
				  void *, xdrproc_t, void *,
				  struct timeval);
	void (*clAbort) (struct CLIENT *);
	void (*clGeterr) (struct CLIENT *, struct rpc_err *);
	int (*clFreeres) (struct CLIENT *, xdrproc_t, void *);
	void (*clDestroy) (struct CLIENT *);
	int (*clMaster) (struct CLIENT *, int, void *);
    } *clOps;
    void *clPrivate;
} node;
extern CLIENT *gssrpcClntrawProduce(rpcprog_t, rpcvers_t);
extern CLIENT *gssrpcClntProduce(char *, rpcprog_t, rpcvers_t, char *);
extern CLIENT *gssrpcClnttcpProduce(struct sockaddr_in *, rpcprog_t,
				    rpcvers_t, int *, u_int, u_int);
extern CLIENT *gssrpcClntudpMake(struct sockaddr_in *, rpcprog_t,
				 rpcvers_t, struct timeval, int *);
extern CLIENT *gssrpcClntudpBufcreate(struct sockaddr_in *, rpcprog_t,
				      rpcvers_t, struct timeval, int *,
				      u_int, u_int);
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
    } cur;
};
struct rejected_reply {
    enum reject_stat rjStat;
    union {
	struct {
	    rpcvers_t low;
	    rpcvers_t high;
	} rjVersion;
	enum auth_stat rjWhy;
    } cur;
};
struct reply_body {
    enum reply_stat rpStat;
    union {
	struct accepted_reply rpAr;
	struct rejected_reply rpDr;
    } cur;
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
    } cur;
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
typedef struct gss_name_struct *gListT;
struct gss_cred_id_struct;
typedef struct gss_cred_id_struct *gCredIdT;
struct gss_ctx_id_struct;
typedef struct gss_ctx_id_struct *gssCtxIdT;
typedef uint32_t gssUint32;
typedef int32_t gInt32;
typedef gss_uint32 omUint32;
typedef struct gss_OID_desc_struct {
    OM_uint32 length;
    void *element;
} gssOidDesc;
typedef struct gss_OID_desc_struct {
    OM_uint32 length;
    void *element;
} *gOid;
typedef struct gss_OID_set_desc_struct {
    size_t count;
    gss_OID element;
} gssOidSetDesc;
typedef struct gss_OID_set_desc_struct {
    size_t count;
    gss_OID element;
} *gssOidSet;
typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} gssBufferDesc;
typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} *gBufferT;
typedef struct gss_channel_bindings_struct {
    OM_uint32 initiatorAddrtype;
    gss_buffer_desc initiatorAddress;
    OM_uint32 acceptorAddrtype;
    gss_buffer_desc acceptorAddress;
    gss_buffer_desc applicationData;
} *gssChannelBindingsT;
typedef OM_uint32 gQopT;
typedef int gssCredUseT;
extern gss_OID gssCNtUserName;
extern gss_OID gCNtMachineUidName;
extern gss_OID gCNtStrUidList;
extern gss_OID gCNtHostbasedServiceX;
extern gss_OID gCNtHostbasedService;
extern gss_OID gssCNtAnonymous;
extern gss_OID gssCNtExportName;
OM_uint32 gGetCred(OM_uint32 *, gss_name_t, OM_uint32, gss_OID_set,
		   gss_cred_usage_t, gss_cred_id_t *, gss_OID_set *,
		   OM_uint32 *);
OM_uint32 gssTurnCred(OM_uint32 *, gss_cred_id_t *);
OM_uint32 gssInitSecContext(OM_uint32 *, gss_cred_id_t, gss_ctx_id_t *,
			    gss_name_t, gss_OID, OM_uint32, OM_uint32,
			    gss_channel_bindings_t, gss_buffer_t,
			    gss_OID *, gss_buffer_t, OM_uint32 *,
			    OM_uint32 *);
OM_uint32 gAcceptSecondContext(OM_uint32 *, gss_ctx_id_t *, gss_cred_id_t,
			       gss_buffer_t, gss_channel_bindings_t,
			       gss_name_t *, gss_OID *, gss_buffer_t,
			       OM_uint32 *, OM_uint32 *, gss_cred_id_t *);
OM_uint32 gssWorkContextToken(OM_uint32 *, gss_ctx_id_t, gss_buffer_t);
OM_uint32 gDeleteSecondContext(OM_uint32 *, gss_ctx_id_t *, gss_buffer_t);
OM_uint32 gssContextTime(OM_uint32 *, gss_ctx_id_t, OM_uint32 *);
OM_uint32 gMakeMic(OM_uint32 *, gss_ctx_id_t, gss_qop_t, gss_buffer_t,
		   gss_buffer_t);
OM_uint32 gssVerifyMic(OM_uint32 *, gss_ctx_id_t, gss_buffer_t,
		       gss_buffer_t, gss_qop_t *);
OM_uint32 gssWrap(OM_uint32 *, gss_ctx_id_t, int, gss_qop_t, gss_buffer_t,
		  int *, gss_buffer_t);
OM_uint32 gUnwrap(OM_uint32 *, gss_ctx_id_t, gss_buffer_t, gss_buffer_t,
		  int *, gss_qop_t *);
OM_uint32 gDisplayStatus(OM_uint32 *, OM_uint32, int, gss_OID, OM_uint32 *,
			 gss_buffer_t);
OM_uint32 gIndicateMechs(OM_uint32 *, gss_OID_set *);
OM_uint32 gCompareName(OM_uint32 *, gss_name_t, gss_name_t, int *);
OM_uint32 gssDisplayName(OM_uint32 *, gss_name_t, gss_buffer_t, gss_OID *);
OM_uint32 gssImportName(OM_uint32 *, gss_buffer_t, gss_OID, gss_name_t *);
OM_uint32 gssFreeList(OM_uint32 *, gss_name_t *);
OM_uint32 gssFreeBuff(OM_uint32 *, gss_buffer_t);
OM_uint32 gssTurnOidSet(OM_uint32 *, gss_OID_set *);
OM_uint32 gInquireCred(OM_uint32 *, gss_cred_id_t, gss_name_t *,
		       OM_uint32 *, gss_cred_usage_t *, gss_OID_set *);
OM_uint32 gssInquireContext(OM_uint32 *, gss_ctx_id_t, gss_name_t *,
			    gss_name_t *, OM_uint32 *, gss_OID *,
			    OM_uint32 *, int *, int *);
OM_uint32 gssWrapSizeLimit(OM_uint32 *, gss_ctx_id_t, int, gss_qop_t,
			   OM_uint32, OM_uint32 *);
OM_uint32 gssImportNameObject(OM_uint32 *, void *, gss_OID, gss_name_t *);
OM_uint32 gssExportListObject(OM_uint32 *, gss_name_t, gss_OID, void **);
OM_uint32 gAddCred(OM_uint32 *, gss_cred_id_t, gss_name_t, gss_OID,
		   gss_cred_usage_t, OM_uint32, OM_uint32, gss_cred_id_t *,
		   gss_OID_set *, OM_uint32 *, OM_uint32 *);
OM_uint32 gssInquireCredByMech(OM_uint32 *, gss_cred_id_t, gss_OID,
			       gss_name_t *, OM_uint32 *, OM_uint32 *,
			       gss_cred_usage_t *);
OM_uint32 gssExportSecContext(OM_uint32 *, gss_ctx_id_t *, gss_buffer_t);
OM_uint32 gImportSecondContext(OM_uint32 *, gss_buffer_t, gss_ctx_id_t *);
OM_uint32 gFreeOid(OM_uint32 *, gss_OID *);
OM_uint32 gssProduceEmptyOidSet(OM_uint32 *, gss_OID_set *);
OM_uint32 gLendOidSetMember(OM_uint32 *, gss_OID, gss_OID_set *);
OM_uint32 gTestOidSetMember(OM_uint32 *, gss_OID, gss_OID_set, int *);
OM_uint32 gssStringToOid(OM_uint32 *, gss_buffer_t, gss_OID *);
OM_uint32 gOidToStr(OM_uint32 *, gss_OID, gss_buffer_t);
OM_uint32 gssInquireListForMech(OM_uint32 *, gss_OID, gss_OID_set *);
OM_uint32 gInquireMechsForName(OM_uint32 *, const gss_name_t,
			       gss_OID_set *);
OM_uint32 gSign(OM_uint32 *, gss_ctx_id_t, int, gss_buffer_t,
		gss_buffer_t);
OM_uint32 gssVerify(OM_uint32 *, gss_ctx_id_t, gss_buffer_t, gss_buffer_t,
		    int *);
OM_uint32 gssSeal(OM_uint32 *, gss_ctx_id_t, int, int, gss_buffer_t, int *,
		  gss_buffer_t);
OM_uint32 gUnseal(OM_uint32 *, gss_ctx_id_t, gss_buffer_t, gss_buffer_t,
		  int *, int *);
OM_uint32 gExportName(OM_uint32 *, const gss_name_t, gss_buffer_t);
OM_uint32 gExtraName(OM_uint32 *, const gss_name_t, gss_name_t *);
OM_uint32 gssCanonicalizeName(OM_uint32 *, const gss_name_t, const gss_OID,
			      gss_name_t *);
OM_uint32 gssPseudoRandom(OM_uint32 *, gss_ctx_id_t, int,
			  const gss_buffer_t, ssize_t, gss_buffer_t);
OM_uint32 gStoreCred(OM_uint32 *, const gss_cred_id_t, gss_cred_usage_t,
		     const gss_OID, OM_uint32, OM_uint32, gss_OID_set *,
		     gss_cred_usage_t *);
OM_uint32 gssSetNegMechs(OM_uint32 *, gss_cred_id_t, const gss_OID_set);
typedef const gss_buffer_desc *gssConstBufferT;
typedef const struct gss_channel_bindings_struct *gConstChannelBindingsT;
typedef const struct gss_ctx_id_struct *gConstCtxIdT;
typedef const struct gss_cred_id_struct *gssConstCredIdT;
typedef const struct gss_name_struct *gssConstNameT;
typedef const gss_OID_desc *gssConstOid;
typedef const gss_OID_set_desc *gConstOidSet;
OM_uint32 gssIndicateMechsByAttrs(OM_uint32 *, gss_const_OID_set,
				  gss_const_OID_set, gss_const_OID_set,
				  gss_OID_set *);
OM_uint32 gssInquireAttrsForMech(OM_uint32 *, gss_const_OID, gss_OID_set *,
				 gss_OID_set *);
OM_uint32 gDisplayMechAttr(OM_uint32 *, gss_const_OID, gss_buffer_t,
			   gss_buffer_t, gss_buffer_t);
extern gss_const_OID gCMaMechConcrete;
extern gss_const_OID gCMaMechPseudo;
extern gss_const_OID gssCMaMechComposite;
extern gss_const_OID gssCMaMechNego;
extern gss_const_OID gssCMaMechGlue;
extern gss_const_OID gCMaNotMech;
extern gss_const_OID gCMaDeprecated;
extern gss_const_OID gssCMaNotDfltMech;
extern gss_const_OID gCMaItokFramed;
extern gss_const_OID gCMaAuthInit;
extern gss_const_OID gCMaAuthTarg;
extern gss_const_OID gssCMaAuthInitInit;
extern gss_const_OID gssCMaAuthTargInit;
extern gss_const_OID gCMaAuthInitAnon;
extern gss_const_OID gssCMaAuthTargAnon;
extern gss_const_OID gCMaDelegCred;
extern gss_const_OID gssCMaIntegProt;
extern gss_const_OID gssCMaConfProt;
extern gss_const_OID gssCMaMic;
extern gss_const_OID gCMaWrap;
extern gss_const_OID gCMaProtReady;
extern gss_const_OID gssCMaReplayDet;
extern gss_const_OID gCMaOosDet;
extern gss_const_OID gCMaCbindings;
extern gss_const_OID gssCMaPfs;
extern gss_const_OID gCMaCompress;
extern gss_const_OID gssCMaCtxTrans;
OM_uint32 gInquireSaslnameForMech(OM_uint32 *, const gss_OID, gss_buffer_t,
				  gss_buffer_t, gss_buffer_t);
OM_uint32 gssInquireMechForSaslname(OM_uint32 *, const gss_buffer_t,
				    gss_OID *);
typedef enum { RPCSEC_GSS_DATA = 0, RPCSEC_GSS_INIT =
	1, RPCSEC_GSS_CONTINUE_INIT = 2, RPCSEC_GSS_DESTROY =
	3 } rpcGProcT;
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
int gssrpcXdrRpcGssBuff(XDR * xdrs, gss_buffer_t, u_int maxsize);
int gssrpcXdrRpcGCred(XDR * xdrs, struct rpc_gss_cred *mem);
int gssrpcXdrRpcGInitArgs(XDR * xdrs, gss_buffer_desc * mem);
int gssrpcXdrRpcGssInitAns(XDR * xdrs, struct rpc_gss_init_res *mem);
int gssrpcXdrRpcGData(XDR * xdrs, xdrproc_t xdrFunc, caddr_t xdrPointer,
		      gss_ctx_id_t ctx, gss_qop_t qop, rpc_gss_svc_t svc,
		      uint32_t seq);
int gssrpcXdrRpcGssWrapData(XDR * xdrs, xdrproc_t xdrFunc,
			    caddr_t xdrPointer, gss_ctx_id_t ctx,
			    gss_qop_t qop, rpc_gss_svc_t svc,
			    uint32_t seq);
int gssrpcXdrRpcGUnwrapData(XDR * xdrs, xdrproc_t xdrFunc,
			    caddr_t xdrPointer, gss_ctx_id_t ctx,
			    gss_qop_t qop, rpc_gss_svc_t svc,
			    uint32_t seq);
AUTH *gssrpcAuthgssMake(CLIENT *, gss_name_t, struct rpc_gss_sec *);
AUTH *gssrpcAuthgssMakeDefault(CLIENT *, char *, struct rpc_gss_sec *);
int gssrpcAuthgssService(AUTH * auth, int svc);
int gssrpcAuthgssGetPrivateData(AUTH * auth,
				struct authgss_private_data *);
struct svc_req;
typedef struct SVCAUTH {
    struct svc_auth_ops {
	int (*svcAhWrap) (struct SVCAUTH *, XDR *, xdrproc_t, caddr_t);
	int (*svcAhUnwrap) (struct SVCAUTH *, XDR *, xdrproc_t, caddr_t);
	int (*svcAhDestroy) (struct SVCAUTH *);
    } *svcAhOps;
    void *svcAhPrivate;
} svcauth;
char *gssrpcSvcauthGMakeStar(SVCAUTH * auth);
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
extern int gssrpcSvcFile(SVCXPRT *, rpcprog_t, rpcvers_t,
			 void (*)(struct svc_req *, SVCXPRT *), int);
extern int gssrpcRegisterrpc(rpcprog_t, rpcvers_t, rpcproc_t,
			     char *(*)(void *), xdrproc_t, xdrproc_t);
extern void gssrpcSvcUnregister(rpcprog_t, rpcvers_t);
extern void gssrpcXprtRegister(SVCXPRT *);
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
extern SVCXPRT *gssrpcSvcrawMake(void);
extern SVCXPRT *gssrpcSvcudpProduce(int);
extern SVCXPRT *gssrpcSvcudpBufcreate(int, u_int, u_int);
extern int gssrpcSvcudpEnablecache(SVCXPRT *, uint32_t);
extern SVCXPRT *gssrpcSvctcpMake(int, u_int, u_int);
extern SVCXPRT *gssrpcSvcfdMake(int, u_int, u_int);
extern int gssrpcGetMyaddress(struct sockaddr_in *);
extern int gssrpcBindresvport(int, struct sockaddr_in *);
extern int gssrpcBindresvportSa(int, struct sockaddr *);
extern int gssrpcCallrpc(char *, rpcprog_t, rpcvers_t, rpcproc_t,
			 xdrproc_t, char *, xdrproc_t, char *);
extern int gssrpcGetrpcport(char *, rpcprog_t, rpcvers_t, rpcprot_t);
extern int gssrpcRpcDtablesize(void);
struct opaque_auth gssrpcNullAuth = { 0 };

int gssrpcSvcFds = 0;
struct gssrpc_rpc_createrr gssrpcRpcCreaterr = { RPC_SUCCESS };

int gssrpcSvcMaxfd = -1;
