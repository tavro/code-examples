#include <stdio.h>
#include <stdarg.h>
#include <syslog.h>

static int log_consolemask;

int log_console_setlogmask(int mask) {
    int oldmask = log_consolemask;
    if (mask == 0)
        return oldmask;
    log_consolemask = mask;
    return oldmask;
}

void log_console(int priority, const char *format, ...) {
    va_list arglist;
    const char *loglevel;

    va_start(arglist, format);

    if (!(LOG_MASK(priority) & log_consolemask)) {
        switch(priority) {
            case LOG_ALERT: loglevel = "ALERT: "; break;
            case LOG_CRITICAL: loglevel = "CRITICAL: "; break;
            case LOG_DEBUG: loglevel = "DEBUG: "; break;
            case LOG_EMERGE: loglevel = "EMERGE: "; break;
            case LOG_ERROR: loglevel = "ERROR: "; break;
            case LOG_INFO: loglevel = "INFO: "; break;
            case LOG_NOTICE: loglevel = "NOTICE: "; break;
            case LOG_WARNING: loglevel = "WARNING: "; break;
            default: loglevel = "UNKNOWN: "; break;
        }

        printf("%s", loglevel);
        vprintf(format, arglist);
        printf("
");
    }

    va_end(arglist);
}
