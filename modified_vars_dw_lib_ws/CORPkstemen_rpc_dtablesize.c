#include <unistd.h>
#include <gssrpc/rpc.h>
enum xdr_op { XDR_ENCODE = 0, XDR_DECODE = 1, XDR_FREE = 2 };
typedef int (*xdrproc_t) ();
typedef struct XDR {
    enum xdr_op x_op;
    struct xdr_ops {
	int (*x_getlong) (struct XDR *, long *);
	int (*x_putlong) (struct XDR *, long *);
	int (*x_getbytes) (struct XDR *, caddr_t, u_int);
	int (*x_putbytes) (struct XDR *, caddr_t, u_int);
	 u_int(*x_getpostn) (struct XDR *);
	int (*x_setpostn) (struct XDR *, u_int);
	rpc_inline_t *(*x_inline) (struct XDR *, int);
	void (*x_destroy) (struct XDR *);
    } *x_ops;
    caddr_t x_public;
    void *x_private;
    caddr_t x_base;
    int x_handy;
} XDR;
struct xdr_discrim {
    int value;
    xdrproc_t proc;
};
extern int gssrpc_xdr_void(XDR *, void *);
extern int gssrpc_xdr_int(XDR *, int *);
extern int gssrpc_xdr_u_int(XDR *, u_int *);
extern int gssrpc_xdr_long(XDR *, long *);
extern int gssrpc_xdr_u_long(XDR *, u_long *);
extern int gssrpc_xdr_short(XDR *, short *);
extern int gssrpc_xdr_u_short(XDR *, u_short *);
extern int gssrpc_xdr_bool(XDR *, int *);
extern int gssrpc_xdr_enum(XDR *, int *);
extern int gssrpc_xdr_array(XDR *, caddr_t *, u_int *, u_int, u_int,
			    xdrproc_t);
extern int gssrpc_xdr_bytes(XDR *, char **, u_int *, u_int);
extern int gssrpc_xdr_opaque(XDR *, caddr_t, u_int);
extern int gssrpc_xdr_string(XDR *, char **, u_int);
extern int gssrpc_xdr_union(XDR *, int *, char *, struct xdr_discrim *,
			    xdrproc_t);
extern int gssrpc_xdr_char(XDR *, char *);
extern int gssrpc_xdr_u_char(XDR *, u_char *);
extern int gssrpc_xdr_vector(XDR *, char *, u_int, u_int, xdrproc_t);
extern int gssrpc_xdr_float(XDR *, float *);
extern int gssrpc_xdr_double(XDR *, double *);
extern int gssrpc_xdr_reference(XDR *, caddr_t *, u_int, xdrproc_t);
extern int gssrpc_xdr_pointer(XDR *, char **, u_int, xdrproc_t);
extern int gssrpc_xdr_wrapstring(XDR *, char **);
extern unsigned long gssrpc_xdr_sizeof(xdrproc_t, void *);
struct netobj {
    u_int n_len;
    char *n_bytes;
};
typedef struct netobj netobj;
extern int gssrpc_xdr_netobj(XDR *, struct netobj *);
extern int gssrpc_xdr_int32(XDR *, int32_t *);
extern int gssrpc_xdr_u_int32(XDR *, uint32_t *);
extern void gssrpc_xdralloc_create(XDR *, enum xdr_op);
extern void gssrpc_xdralloc_release(XDR *);
extern caddr_t gssrpc_xdralloc_getdata(XDR *);
extern void gssrpc_xdrmem_create(XDR *, caddr_t, u_int, enum xdr_op);
extern void gssrpc_xdrstdio_create(XDR *, FILE *, enum xdr_op);
extern void gssrpc_xdrrec_create(XDR * xdrs, u_int, u_int, caddr_t,
				 int (*)(caddr_t, caddr_t, int),
				 int (*)(caddr_t, caddr_t, int));
extern int gssrpc_xdrrec_endofrecord(XDR *, int);
extern int gssrpc_xdrrec_skiprecord(XDR * xdrs);
extern int gssrpc_xdrrec_eof(XDR * xdrs);
extern void gssrpc_xdr_free(xdrproc_t, void *);
enum auth_stat { AUTH_OK = 0, AUTH_BADCRED = 1, AUTH_REJECTEDCRED =
	2, AUTH_BADVERF = 3, AUTH_REJECTEDVERF = 4, AUTH_TOOWEAK =
	5, AUTH_INVALIDRESP = 6, AUTH_FAILED = 7, RPCSEC_GSS_CREDPROBLEM =
	13, RPCSEC_GSS_CTXPROBLEM = 14 };
union des_block {
    char c[8];
};
typedef union des_block des_block;
extern int gssrpc_xdr_des_block(XDR *, des_block *);
struct opaque_auth {
    int oa_flavor;
    caddr_t oa_base;
    u_int oa_length;
};
struct rpc_msg;
typedef struct AUTH {
    struct opaque_auth ah_cred;
    struct opaque_auth ah_verf;
    union des_block ah_key;
    struct auth_ops {
	void (*ah_nextverf) (struct AUTH *);
	int (*ah_marshal) (struct AUTH *, XDR *);
	int (*ah_validate) (struct AUTH *, struct opaque_auth *);
	int (*ah_refresh) (struct AUTH *, struct rpc_msg *);
	void (*ah_destroy) (struct AUTH *);
	int (*ah_wrap) (struct AUTH *, XDR *, xdrproc_t, caddr_t);
	int (*ah_unwrap) (struct AUTH *, XDR *, xdrproc_t, caddr_t);
    } *ah_ops;
    void *ah_private;
} AUTH;
extern AUTH *gssrpc_authunix_create(char *machname, int uid, int gid,
				    int len, int *aup_gids);
extern AUTH *gssrpc_authunix_create_default(void);
extern AUTH *gssrpc_authnone_create(void);
extern AUTH *gssrpc_authdes_create();
extern int gssrpc_xdr_opaque_auth(XDR *, struct opaque_auth *);
enum clnt_stat { RPC_SUCCESS = 0, RPC_CANTENCODEARGS =
	1, RPC_CANTDECODERES = 2, RPC_CANTSEND = 3, RPC_CANTRECV =
	4, RPC_TIMEDOUT = 5, RPC_VERSMISMATCH = 6, RPC_AUTHERROR =
	7, RPC_PROGUNAVAIL = 8, RPC_PROGVERSMISMATCH = 9, RPC_PROCUNAVAIL =
	10, RPC_CANTDECODEARGS = 11, RPC_SYSTEMERROR =
	12, RPC_UNKNOWNHOST = 13, RPC_UNKNOWNPROTO = 17, RPC_PMAPFAILURE =
	14, RPC_PROGNOTREGISTERED = 15, RPC_FAILED = 16 };
struct rpc_err {
    enum clnt_stat re_status;
    union {
	int RE_errno;
	enum auth_stat RE_why;
	struct {
	    rpcvers_t low;
	    rpcvers_t high;
	} RE_vers;
	struct {
	    int32_t s1;
	    int32_t s2;
	} RE_lb;
    } ru;
};
typedef struct CLIENT {
    AUTH *cl_auth;
    struct clnt_ops {
	enum clnt_stat (*cl_call) (struct CLIENT *, rpcproc_t, xdrproc_t,
				   void *, xdrproc_t, void *,
				   struct timeval);
	void (*cl_abort) (struct CLIENT *);
	void (*cl_geterr) (struct CLIENT *, struct rpc_err *);
	int (*cl_freeres) (struct CLIENT *, xdrproc_t, void *);
	void (*cl_destroy) (struct CLIENT *);
	int (*cl_control) (struct CLIENT *, int, void *);
    } *cl_ops;
    void *cl_private;
} CLIENT;
extern CLIENT *gssrpc_clntraw_create(rpcprog_t, rpcvers_t);
extern CLIENT *gssrpc_clnt_create(char *, rpcprog_t, rpcvers_t, char *);
extern CLIENT *gssrpc_clnttcp_create(struct sockaddr_in *, rpcprog_t,
				     rpcvers_t, int *, u_int, u_int);
extern CLIENT *gssrpc_clntudp_create(struct sockaddr_in *, rpcprog_t,
				     rpcvers_t, struct timeval, int *);
extern CLIENT *gssrpc_clntudp_bufcreate(struct sockaddr_in *, rpcprog_t,
					rpcvers_t, struct timeval, int *,
					u_int, u_int);
void gssrpc_clnt_pcreateerror(char *);
char *gssrpc_clnt_spcreateerror(char *);
void gssrpc_clnt_perrno(enum clnt_stat);
void gssrpc_clnt_perror(CLIENT *, char *);
char *gssrpc_clnt_sperror(CLIENT *, char *);
struct gssrpc_rpc_createrr {
    enum clnt_stat cf_stat;
    struct rpc_err cf_error;
};
extern struct gssrpc_rpc_createrr gssrpc_rpc_createrr;
char *gssrpc_clnt_sperrno(enum clnt_stat num);
enum msg_type { CALL = 0, REPLY = 1 };
enum reply_stat { MSG_ACCEPTED = 0, MSG_DENIED = 1 };
enum accept_stat { SUCCESS = 0, PROG_UNAVAIL = 1, PROG_MISMATCH =
	2, PROC_UNAVAIL = 3, GARBAGE_ARGS = 4, SYSTEM_ERR = 5 };
enum reject_stat { RPC_MISMATCH = 0, AUTH_ERROR = 1 };
struct accepted_reply {
    struct opaque_auth ar_verf;
    enum accept_stat ar_stat;
    union {
	struct {
	    rpcvers_t low;
	    rpcvers_t high;
	} AR_versions;
	struct {
	    caddr_t where;
	    xdrproc_t proc;
	} AR_results;
    } ru;
};
struct rejected_reply {
    enum reject_stat rj_stat;
    union {
	struct {
	    rpcvers_t low;
	    rpcvers_t high;
	} RJ_versions;
	enum auth_stat RJ_why;
    } ru;
};
struct reply_body {
    enum reply_stat rp_stat;
    union {
	struct accepted_reply RP_ar;
	struct rejected_reply RP_dr;
    } ru;
};
struct call_body {
    rpcvers_t cb_rpcvers;
    rpcprog_t cb_prog;
    rpcvers_t cb_vers;
    rpcproc_t cb_proc;
    struct opaque_auth cb_cred;
    struct opaque_auth cb_verf;
};
struct rpc_msg {
    uint32_t rm_xid;
    enum msg_type rm_direction;
    union {
	struct call_body RM_cmb;
	struct reply_body RM_rmb;
    } ru;
};
extern int gssrpc_xdr_callmsg(XDR *, struct rpc_msg *);
extern int gssrpc_xdr_callhdr(XDR *, struct rpc_msg *);
extern int gssrpc_xdr_replymsg(XDR *, struct rpc_msg *);
extern void gssrpc__seterr_reply(struct rpc_msg *, struct rpc_err *);
extern int gssrpc_xdr_accepted_reply(XDR *, struct accepted_reply *);
extern int gssrpc_xdr_rejected_reply(XDR *, struct rejected_reply *);
struct authunix_parms {
    uint32_t aup_time;
    char *aup_machname;
    int aup_uid;
    int aup_gid;
    u_int aup_len;
    int *aup_gids;
};
extern int gssrpc_xdr_authunix_parms(XDR *, struct authunix_parms *);
struct short_hand_verf {
    struct opaque_auth new_cred;
};
struct gss_name_struct;
typedef struct gss_name_struct *gss_name_t;
struct gss_cred_id_struct;
typedef struct gss_cred_id_struct *gss_cred_id_t;
struct gss_ctx_id_struct;
typedef struct gss_ctx_id_struct *gss_ctx_id_t;
typedef uint32_t gss_uint32;
typedef int32_t gss_int32;
typedef gss_uint32 OM_uint32;
typedef struct gss_OID_desc_struct {
    OM_uint32 length;
    void *elements;
} gss_OID_desc;
typedef struct gss_OID_desc_struct {
    OM_uint32 length;
    void *elements;
} *gss_OID;
typedef struct gss_OID_set_desc_struct {
    size_t count;
    gss_OID elements;
} gss_OID_set_desc;
typedef struct gss_OID_set_desc_struct {
    size_t count;
    gss_OID elements;
} *gss_OID_set;
typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} gss_buffer_desc;
typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} *gss_buffer_t;
typedef struct gss_channel_bindings_struct {
    OM_uint32 initiator_addrtype;
    gss_buffer_desc initiator_address;
    OM_uint32 acceptor_addrtype;
    gss_buffer_desc acceptor_address;
    gss_buffer_desc application_data;
} *gss_channel_bindings_t;
typedef OM_uint32 gss_qop_t;
typedef int gss_cred_usage_t;
extern gss_OID GSS_C_NT_USER_NAME;
extern gss_OID GSS_C_NT_MACHINE_UID_NAME;
extern gss_OID GSS_C_NT_STRING_UID_NAME;
extern gss_OID GSS_C_NT_HOSTBASED_SERVICE_X;
extern gss_OID GSS_C_NT_HOSTBASED_SERVICE;
extern gss_OID GSS_C_NT_ANONYMOUS;
extern gss_OID GSS_C_NT_EXPORT_NAME;
OM_uint32 gss_acquire_cred(OM_uint32 *, gss_name_t, OM_uint32, gss_OID_set,
			   gss_cred_usage_t, gss_cred_id_t *,
			   gss_OID_set *, OM_uint32 *);
OM_uint32 gss_release_cred(OM_uint32 *, gss_cred_id_t *);
OM_uint32 gss_init_sec_context(OM_uint32 *, gss_cred_id_t, gss_ctx_id_t *,
			       gss_name_t, gss_OID, OM_uint32, OM_uint32,
			       gss_channel_bindings_t, gss_buffer_t,
			       gss_OID *, gss_buffer_t, OM_uint32 *,
			       OM_uint32 *);
OM_uint32 gss_accept_sec_context(OM_uint32 *, gss_ctx_id_t *,
				 gss_cred_id_t, gss_buffer_t,
				 gss_channel_bindings_t, gss_name_t *,
				 gss_OID *, gss_buffer_t, OM_uint32 *,
				 OM_uint32 *, gss_cred_id_t *);
OM_uint32 gss_process_context_token(OM_uint32 *, gss_ctx_id_t,
				    gss_buffer_t);
OM_uint32 gss_delete_sec_context(OM_uint32 *, gss_ctx_id_t *,
				 gss_buffer_t);
OM_uint32 gss_context_time(OM_uint32 *, gss_ctx_id_t, OM_uint32 *);
OM_uint32 gss_get_mic(OM_uint32 *, gss_ctx_id_t, gss_qop_t, gss_buffer_t,
		      gss_buffer_t);
OM_uint32 gss_verify_mic(OM_uint32 *, gss_ctx_id_t, gss_buffer_t,
			 gss_buffer_t, gss_qop_t *);
OM_uint32 gss_wrap(OM_uint32 *, gss_ctx_id_t, int, gss_qop_t, gss_buffer_t,
		   int *, gss_buffer_t);
OM_uint32 gss_unwrap(OM_uint32 *, gss_ctx_id_t, gss_buffer_t, gss_buffer_t,
		     int *, gss_qop_t *);
OM_uint32 gss_display_status(OM_uint32 *, OM_uint32, int, gss_OID,
			     OM_uint32 *, gss_buffer_t);
OM_uint32 gss_indicate_mechs(OM_uint32 *, gss_OID_set *);
OM_uint32 gss_compare_name(OM_uint32 *, gss_name_t, gss_name_t, int *);
OM_uint32 gss_display_name(OM_uint32 *, gss_name_t, gss_buffer_t,
			   gss_OID *);
OM_uint32 gss_import_name(OM_uint32 *, gss_buffer_t, gss_OID,
			  gss_name_t *);
OM_uint32 gss_release_name(OM_uint32 *, gss_name_t *);
OM_uint32 gss_release_buffer(OM_uint32 *, gss_buffer_t);
OM_uint32 gss_release_oid_set(OM_uint32 *, gss_OID_set *);
OM_uint32 gss_inquire_cred(OM_uint32 *, gss_cred_id_t, gss_name_t *,
			   OM_uint32 *, gss_cred_usage_t *, gss_OID_set *);
OM_uint32 gss_inquire_context(OM_uint32 *, gss_ctx_id_t, gss_name_t *,
			      gss_name_t *, OM_uint32 *, gss_OID *,
			      OM_uint32 *, int *, int *);
OM_uint32 gss_wrap_size_limit(OM_uint32 *, gss_ctx_id_t, int, gss_qop_t,
			      OM_uint32, OM_uint32 *);
OM_uint32 gss_import_name_object(OM_uint32 *, void *, gss_OID,
				 gss_name_t *);
OM_uint32 gss_export_name_object(OM_uint32 *, gss_name_t, gss_OID,
				 void **);
OM_uint32 gss_add_cred(OM_uint32 *, gss_cred_id_t, gss_name_t, gss_OID,
		       gss_cred_usage_t, OM_uint32, OM_uint32,
		       gss_cred_id_t *, gss_OID_set *, OM_uint32 *,
		       OM_uint32 *);
OM_uint32 gss_inquire_cred_by_mech(OM_uint32 *, gss_cred_id_t, gss_OID,
				   gss_name_t *, OM_uint32 *, OM_uint32 *,
				   gss_cred_usage_t *);
OM_uint32 gss_export_sec_context(OM_uint32 *, gss_ctx_id_t *,
				 gss_buffer_t);
OM_uint32 gss_import_sec_context(OM_uint32 *, gss_buffer_t,
				 gss_ctx_id_t *);
OM_uint32 gss_release_oid(OM_uint32 *, gss_OID *);
OM_uint32 gss_create_empty_oid_set(OM_uint32 *, gss_OID_set *);
OM_uint32 gss_add_oid_set_member(OM_uint32 *, gss_OID, gss_OID_set *);
OM_uint32 gss_test_oid_set_member(OM_uint32 *, gss_OID, gss_OID_set,
				  int *);
OM_uint32 gss_str_to_oid(OM_uint32 *, gss_buffer_t, gss_OID *);
OM_uint32 gss_oid_to_str(OM_uint32 *, gss_OID, gss_buffer_t);
OM_uint32 gss_inquire_names_for_mech(OM_uint32 *, gss_OID, gss_OID_set *);
OM_uint32 gss_inquire_mechs_for_name(OM_uint32 *, const gss_name_t,
				     gss_OID_set *);
OM_uint32 gss_sign(OM_uint32 *, gss_ctx_id_t, int, gss_buffer_t,
		   gss_buffer_t);
OM_uint32 gss_verify(OM_uint32 *, gss_ctx_id_t, gss_buffer_t, gss_buffer_t,
		     int *);
OM_uint32 gss_seal(OM_uint32 *, gss_ctx_id_t, int, int, gss_buffer_t,
		   int *, gss_buffer_t);
OM_uint32 gss_unseal(OM_uint32 *, gss_ctx_id_t, gss_buffer_t, gss_buffer_t,
		     int *, int *);
OM_uint32 gss_export_name(OM_uint32 *, const gss_name_t, gss_buffer_t);
OM_uint32 gss_duplicate_name(OM_uint32 *, const gss_name_t, gss_name_t *);
OM_uint32 gss_canonicalize_name(OM_uint32 *, const gss_name_t,
				const gss_OID, gss_name_t *);
OM_uint32 gss_pseudo_random(OM_uint32 *, gss_ctx_id_t, int,
			    const gss_buffer_t, ssize_t, gss_buffer_t);
OM_uint32 gss_store_cred(OM_uint32 *, const gss_cred_id_t,
			 gss_cred_usage_t, const gss_OID, OM_uint32,
			 OM_uint32, gss_OID_set *, gss_cred_usage_t *);
OM_uint32 gss_set_neg_mechs(OM_uint32 *, gss_cred_id_t, const gss_OID_set);
typedef const gss_buffer_desc *gss_const_buffer_t;
typedef const struct gss_channel_bindings_struct
    *gss_const_channel_bindings_t;
typedef const struct gss_ctx_id_struct *gss_const_ctx_id_t;
typedef const struct gss_cred_id_struct *gss_const_cred_id_t;
typedef const struct gss_name_struct *gss_const_name_t;
typedef const gss_OID_desc *gss_const_OID;
typedef const gss_OID_set_desc *gss_const_OID_set;
OM_uint32 gss_indicate_mechs_by_attrs(OM_uint32 *, gss_const_OID_set,
				      gss_const_OID_set, gss_const_OID_set,
				      gss_OID_set *);
OM_uint32 gss_inquire_attrs_for_mech(OM_uint32 *, gss_const_OID,
				     gss_OID_set *, gss_OID_set *);
OM_uint32 gss_display_mech_attr(OM_uint32 *, gss_const_OID, gss_buffer_t,
				gss_buffer_t, gss_buffer_t);
extern gss_const_OID GSS_C_MA_MECH_CONCRETE;
extern gss_const_OID GSS_C_MA_MECH_PSEUDO;
extern gss_const_OID GSS_C_MA_MECH_COMPOSITE;
extern gss_const_OID GSS_C_MA_MECH_NEGO;
extern gss_const_OID GSS_C_MA_MECH_GLUE;
extern gss_const_OID GSS_C_MA_NOT_MECH;
extern gss_const_OID GSS_C_MA_DEPRECATED;
extern gss_const_OID GSS_C_MA_NOT_DFLT_MECH;
extern gss_const_OID GSS_C_MA_ITOK_FRAMED;
extern gss_const_OID GSS_C_MA_AUTH_INIT;
extern gss_const_OID GSS_C_MA_AUTH_TARG;
extern gss_const_OID GSS_C_MA_AUTH_INIT_INIT;
extern gss_const_OID GSS_C_MA_AUTH_TARG_INIT;
extern gss_const_OID GSS_C_MA_AUTH_INIT_ANON;
extern gss_const_OID GSS_C_MA_AUTH_TARG_ANON;
extern gss_const_OID GSS_C_MA_DELEG_CRED;
extern gss_const_OID GSS_C_MA_INTEG_PROT;
extern gss_const_OID GSS_C_MA_CONF_PROT;
extern gss_const_OID GSS_C_MA_MIC;
extern gss_const_OID GSS_C_MA_WRAP;
extern gss_const_OID GSS_C_MA_PROT_READY;
extern gss_const_OID GSS_C_MA_REPLAY_DET;
extern gss_const_OID GSS_C_MA_OOS_DET;
extern gss_const_OID GSS_C_MA_CBINDINGS;
extern gss_const_OID GSS_C_MA_PFS;
extern gss_const_OID GSS_C_MA_COMPRESS;
extern gss_const_OID GSS_C_MA_CTX_TRANS;
OM_uint32 gss_inquire_saslname_for_mech(OM_uint32 *, const gss_OID,
					gss_buffer_t, gss_buffer_t,
					gss_buffer_t);
OM_uint32 gss_inquire_mech_for_saslname(OM_uint32 *, const gss_buffer_t,
					gss_OID *);
typedef enum { RPCSEC_GSS_DATA = 0, RPCSEC_GSS_INIT =
	1, RPCSEC_GSS_CONTINUE_INIT = 2, RPCSEC_GSS_DESTROY =
	3 } rpc_gss_proc_t;
typedef enum { RPCSEC_GSS_SVC_NONE = 1, RPCSEC_GSS_SVC_INTEGRITY =
	2, RPCSEC_GSS_SVC_PRIVACY = 3 } rpc_gss_svc_t;
struct rpc_gss_sec {
    gss_OID mech;
    gss_qop_t qop;
    rpc_gss_svc_t svc;
    gss_cred_id_t cred;
    uint32_t req_flags;
};
struct authgss_private_data {
    gss_ctx_id_t pd_ctx;
    gss_buffer_desc pd_ctx_hndl;
    uint32_t pd_seq_win;
};
struct rpc_gss_cred {
    u_int gc_v;
    rpc_gss_proc_t gc_proc;
    uint32_t gc_seq;
    rpc_gss_svc_t gc_svc;
    gss_buffer_desc gc_ctx;
};
struct rpc_gss_init_res {
    gss_buffer_desc gr_ctx;
    uint32_t gr_major;
    uint32_t gr_minor;
    uint32_t gr_win;
    gss_buffer_desc gr_token;
};
int gssrpc_xdr_rpc_gss_buf(XDR * xdrs, gss_buffer_t, u_int maxsize);
int gssrpc_xdr_rpc_gss_cred(XDR * xdrs, struct rpc_gss_cred *p);
int gssrpc_xdr_rpc_gss_init_args(XDR * xdrs, gss_buffer_desc * p);
int gssrpc_xdr_rpc_gss_init_res(XDR * xdrs, struct rpc_gss_init_res *p);
int gssrpc_xdr_rpc_gss_data(XDR * xdrs, xdrproc_t xdr_func,
			    caddr_t xdr_ptr, gss_ctx_id_t ctx,
			    gss_qop_t qop, rpc_gss_svc_t svc,
			    uint32_t seq);
int gssrpc_xdr_rpc_gss_wrap_data(XDR * xdrs, xdrproc_t xdr_func,
				 caddr_t xdr_ptr, gss_ctx_id_t ctx,
				 gss_qop_t qop, rpc_gss_svc_t svc,
				 uint32_t seq);
int gssrpc_xdr_rpc_gss_unwrap_data(XDR * xdrs, xdrproc_t xdr_func,
				   caddr_t xdr_ptr, gss_ctx_id_t ctx,
				   gss_qop_t qop, rpc_gss_svc_t svc,
				   uint32_t seq);
AUTH *gssrpc_authgss_create(CLIENT *, gss_name_t, struct rpc_gss_sec *);
AUTH *gssrpc_authgss_create_default(CLIENT *, char *,
				    struct rpc_gss_sec *);
int gssrpc_authgss_service(AUTH * auth, int svc);
int gssrpc_authgss_get_private_data(AUTH * auth,
				    struct authgss_private_data *);
struct svc_req;
typedef struct SVCAUTH {
    struct svc_auth_ops {
	int (*svc_ah_wrap) (struct SVCAUTH *, XDR *, xdrproc_t, caddr_t);
	int (*svc_ah_unwrap) (struct SVCAUTH *, XDR *, xdrproc_t, caddr_t);
	int (*svc_ah_destroy) (struct SVCAUTH *);
    } *svc_ah_ops;
    void *svc_ah_private;
} SVCAUTH;
char *gssrpc_svcauth_gss_get_principal(SVCAUTH * auth);
int gssrpc_svcauth_gss_set_svc_name(gss_name_t name);
enum xprt_stat { XPRT_DIED, XPRT_MOREREQS, XPRT_IDLE };
typedef struct SVCXPRT {
    int xp_sock;
    u_short xp_port;
    struct xp_ops {
	int (*xp_recv) (struct SVCXPRT *, struct rpc_msg *);
	enum xprt_stat (*xp_stat) (struct SVCXPRT *);
	int (*xp_getargs) (struct SVCXPRT *, xdrproc_t, void *);
	int (*xp_reply) (struct SVCXPRT *, struct rpc_msg *);
	int (*xp_freeargs) (struct SVCXPRT *, xdrproc_t, void *);
	void (*xp_destroy) (struct SVCXPRT *);
    } *xp_ops;
    int xp_addrlen;
    struct sockaddr_in xp_raddr;
    struct opaque_auth xp_verf;
    SVCAUTH *xp_auth;
    void *xp_p1;
    void *xp_p2;
    int xp_laddrlen;
    struct sockaddr_in xp_laddr;
} SVCXPRT;
struct svc_req {
    rpcprog_t rq_prog;
    rpcvers_t rq_vers;
    rpcproc_t rq_proc;
    struct opaque_auth rq_cred;
    void *rq_clntcred;
    void *rq_svccred;
    void *rq_clntname;
    SVCXPRT *rq_xprt;
};
extern int gssrpc_svc_register(SVCXPRT *, rpcprog_t, rpcvers_t,
			       void (*)(struct svc_req *, SVCXPRT *), int);
extern int gssrpc_registerrpc(rpcprog_t, rpcvers_t, rpcproc_t,
			      char *(*)(void *), xdrproc_t, xdrproc_t);
extern void gssrpc_svc_unregister(rpcprog_t, rpcvers_t);
extern void gssrpc_xprt_register(SVCXPRT *);
extern void gssrpc_xprt_unregister(SVCXPRT *);
extern int gssrpc_svc_sendreply(SVCXPRT *, xdrproc_t, caddr_t);
extern void gssrpc_svcerr_decode(SVCXPRT *);
extern void gssrpc_svcerr_weakauth(SVCXPRT *);
extern void gssrpc_svcerr_noproc(SVCXPRT *);
extern void gssrpc_svcerr_progvers(SVCXPRT *, rpcvers_t, rpcvers_t);
extern void gssrpc_svcerr_auth(SVCXPRT *, enum auth_stat);
extern void gssrpc_svcerr_noprog(SVCXPRT *);
extern void gssrpc_svcerr_systemerr(SVCXPRT *);
extern int gssrpc_svc_maxfd;
extern int gssrpc_svc_fds;
extern int gssrpc_svc_maxfd;
extern void gssrpc_rpctest_service();
extern void gssrpc_svc_getreq(int);
extern void gssrpc_svc_getreqset(int *);
extern void gssrpc_svc_run(void);
extern SVCXPRT *gssrpc_svcraw_create(void);
extern SVCXPRT *gssrpc_svcudp_create(int);
extern SVCXPRT *gssrpc_svcudp_bufcreate(int, u_int, u_int);
extern int gssrpc_svcudp_enablecache(SVCXPRT *, uint32_t);
extern SVCXPRT *gssrpc_svctcp_create(int, u_int, u_int);
extern SVCXPRT *gssrpc_svcfd_create(int, u_int, u_int);
extern int gssrpc_get_myaddress(struct sockaddr_in *);
extern int gssrpc_bindresvport(int, struct sockaddr_in *);
extern int gssrpc_bindresvport_sa(int, struct sockaddr *);
extern int gssrpc_callrpc(char *, rpcprog_t, rpcvers_t, rpcproc_t,
			  xdrproc_t, char *, xdrproc_t, char *);
extern int gssrpc_getrpcport(char *, rpcprog_t, rpcvers_t, rpcprot_t);
extern int gssrpc__rpc_dtablesize(void);
int gssrpc__rpc_dtablesize(void)
{
    int first_iteration;
    static int size;
    if (size == 0) {
	size = getdtablesize();
    }
    return size;
}
