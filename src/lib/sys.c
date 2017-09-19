#include <espace/sys.h>

#include <errno.h>

#define _SYS_ERRDEF(err_symbol, err_str) \
    ESPACE_ERRDEF(SYS_DOME, SYS_##err_symbol, err_symbol, err_str);

ESPACE_DOMDEF(SYS_DOME, "system")
_SYS_ERRDEF(E2BIG, "Argument list too long")
_SYS_ERRDEF(EACCES, "Permission denied")
_SYS_ERRDEF(EADDRINUSE, "Address already in use")
_SYS_ERRDEF(EADDRNOTAVAIL, "Address not available")
_SYS_ERRDEF(EAFNOSUPPORT, "Address family not supported")
_SYS_ERRDEF(EAGAIN, "Resource temporarily unavaiable")
_SYS_ERRDEF(EALREADY, "Connection already in progress")
_SYS_ERRDEF(EBADE, "Invalid exchange")
_SYS_ERRDEF(EBADF, "Bad file descriptor")
_SYS_ERRDEF(EBADFD, "File descriptor in bad state")
_SYS_ERRDEF(EBADMSG, "Bad message")
_SYS_ERRDEF(EBADR, "Invalid request descriptor")
_SYS_ERRDEF(EBADRQC, "Invaild request code")
_SYS_ERRDEF(EBADSLT, "Invalid slot")
_SYS_ERRDEF(EBUSY, "Device or resource busy")
_SYS_ERRDEF(ECANCELED, "Operation canceled")
_SYS_ERRDEF(ECHILD, "No child processes")
_SYS_ERRDEF(ECHRNG, "Channel number out of range")
_SYS_ERRDEF(ECOMM, "Communication error on send")
_SYS_ERRDEF(ECONNABORTED, "Connection aborted")
_SYS_ERRDEF(ECONNREFUSED, "Connection refused")
_SYS_ERRDEF(ECONNRESET, "Connection reset")
_SYS_ERRDEF(EDEADLK, "Resource deadlock avoided")
_SYS_ERRDEF(EDEADLOCK, "Resource deadlock avoided")
_SYS_ERRDEF(EDESTADDRREQ, "Destination address required")
_SYS_ERRDEF(EDOM, "Mathematics argument out of domain of function")
_SYS_ERRDEF(EDQUOT, "Disk quota exceeded")
_SYS_ERRDEF(EEXIST, "File exists")
_SYS_ERRDEF(EFAULT, "Bad address")
_SYS_ERRDEF(EFBIG, "File too large")
_SYS_ERRDEF(EHOSTDOWN, "Host is down")
_SYS_ERRDEF(EHOSTUNREACH, "Host is unreachable")
_SYS_ERRDEF(EIDRM, "Identifier removed")
_SYS_ERRDEF(EILSEQ, "Invalid or incomplete multibyte or wide character")
_SYS_ERRDEF(EINPROGRESS, "Operation in progress")
_SYS_ERRDEF(EINTR, "Interrupted function call")
_SYS_ERRDEF(EINVAL, "Invalid argument")
_SYS_ERRDEF(EIO, "Input/ouput error");
_SYS_ERRDEF(EISCONN, "Socket is connected")
_SYS_ERRDEF(EISDIR, "Is a directory")
_SYS_ERRDEF(EISNAM, "Is a named type file")
_SYS_ERRDEF(EKEYEXPIRED, "Key has expired")
_SYS_ERRDEF(EKEYREJECTED, "Key was rejected by service")
_SYS_ERRDEF(EKEYREVOKED, "Key has been revoked")
_SYS_ERRDEF(EL2HLT, "Level 2 halted")
_SYS_ERRDEF(EL2NSYNC, "Level 2 not synchronized")
_SYS_ERRDEF(EL3HLT, "Level 3 halted")
_SYS_ERRDEF(EL3RST, "Level 3 halted")
_SYS_ERRDEF(ELIBACC, "Cannot access a needed shared library")
_SYS_ERRDEF(ELIBBAD, "Accessing a corrupted shared library")
_SYS_ERRDEF(ELIBMAX, "Attemping to link in too many shared libraries")
_SYS_ERRDEF(ELIBSCN, ".lib section in a.out corrupted")
_SYS_ERRDEF(ELIBEXEC, "Cannot exec a shared library directly")
_SYS_ERRDEF(ELOOP, "Too many levels of symbolic links")
_SYS_ERRDEF(EMEDIUMTYPE, "Wrong medium type")
_SYS_ERRDEF(EMFILE, "Too many open files")
_SYS_ERRDEF(EMLINK, "Too many links")
_SYS_ERRDEF(EMSGSIZE, "Message too long")
_SYS_ERRDEF(EMULTIHOP, "Multihop attempted")
_SYS_ERRDEF(ENAMETOOLONG, "Filename too long")
_SYS_ERRDEF(ENETDOWN, "Network is down")
_SYS_ERRDEF(ENETRESET, "Connection aborted by network")
_SYS_ERRDEF(ENETUNREACH, "Network unreachable")
_SYS_ERRDEF(ENFILE, "Too many open files in system")
_SYS_ERRDEF(ENOBUFS, "No buffer space avaiable")
_SYS_ERRDEF(ENODATA, "No message is avaiable on the STREAM head read queue")
_SYS_ERRDEF(ENODEV, "No such device")
_SYS_ERRDEF(ENOENT, "No such file or directory")
_SYS_ERRDEF(ENOEXEC, "Exec format error")
_SYS_ERRDEF(ENOKEY, "Required key not avaiable")
_SYS_ERRDEF(ENOLCK, "No locks avaiable")
_SYS_ERRDEF(ENOLINK, "Link has been servered")
_SYS_ERRDEF(ENOMEDIUM, "No medium found")
_SYS_ERRDEF(ENOMEM, "Not enough space")
_SYS_ERRDEF(ENOMSG, "No message of the desired type")
_SYS_ERRDEF(ENONET, "Machine is not on the network")
_SYS_ERRDEF(ENOPKG, "Package not installed")
_SYS_ERRDEF(ENOPROTOOPT, "Protocol not avaiable")
_SYS_ERRDEF(ENOSPC, "No space left on device")
_SYS_ERRDEF(ENOSR, "No STREAM resources")
_SYS_ERRDEF(ENOSTR, "Not a STREAM")
_SYS_ERRDEF(ENOSYS, "Function not implemented")
_SYS_ERRDEF(ENOTBLK, "Block device required")
_SYS_ERRDEF(ENOTCONN, "The socket is not connected")
_SYS_ERRDEF(ENOTDIR, "Not a directory")
_SYS_ERRDEF(ENOTEMPTY, "Directory not empty")
_SYS_ERRDEF(ENOTSOCK, "Not a socket")
_SYS_ERRDEF(ENOTSUP, "Operation not supported")
_SYS_ERRDEF(ENOTTY, "Inappropriate I/O control operation")
_SYS_ERRDEF(ENOTUNIQ, "Name not unique on network")
_SYS_ERRDEF(ENXIO, "No such device or address")
_SYS_ERRDEF(EOPNOTSUPP, "Operation not supported on sokcet")
_SYS_ERRDEF(EOVERFLOW, "Value too large to be stored in data type")
_SYS_ERRDEF(EPERM, "Operation not permitted")
_SYS_ERRDEF(EPFNOSUPPORT, "Protocol familiy not supported")
_SYS_ERRDEF(EPIPE, "Broken pipe")
_SYS_ERRDEF(EPROTO, "Protocol error")
_SYS_ERRDEF(EPROTONOSUPPORT, "Protocol not supported")
_SYS_ERRDEF(EPROTOTYPE, "Protocol wrong type for socket")
_SYS_ERRDEF(ERANGE, "Result too large")
_SYS_ERRDEF(EREMCHG, "Remote address changed")
_SYS_ERRDEF(EREMOTE, "Object is remote")
_SYS_ERRDEF(EREMOTEIO, "Remote I/0 error")
_SYS_ERRDEF(ERESTART, "Interrupted system call should be restarted")
_SYS_ERRDEF(EROFS, "Read-only filesystem")
_SYS_ERRDEF(ESHUTDOWN, "Cannot send after transport endpoint shutdown")
_SYS_ERRDEF(ESPIPE, "Invalid seek")
_SYS_ERRDEF(ESOCKTNOSUPPORT, "Socket type not suported")
_SYS_ERRDEF(ESRCH, "No such process")
_SYS_ERRDEF(ESTALE, "Stale file handle")
_SYS_ERRDEF(ESTRPIPE, "Streams pipe error")
_SYS_ERRDEF(ETIME, "Timer expired")
_SYS_ERRDEF(ETIMEDOUT, "Connection timed out")
_SYS_ERRDEF(ETXTBSY, "Text file busy")
_SYS_ERRDEF(EUCLEAN, "Structure needs cleaning")
_SYS_ERRDEF(EUNATCH, "Protocol driver not attached")
_SYS_ERRDEF(EUSERS, "Too many users")
_SYS_ERRDEF(EWOULDBLOCK, "Operation would block")
_SYS_ERRDEF(EXDEV, "Improper link")
_SYS_ERRDEF(EXFULL, "Exchange full")