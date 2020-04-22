#ifndef _SYS_XCORE_H
#define _SYS_XCORE_H

#include "kfile.h"
#include "types.h"
#include "trigger.h"
#include "res.h"
#include "ktime.h"

/* process */
pid_t fork();
void exit(int status);
int wait(int *status);
int execraw(char *name, char *argv[]);
int execfile(char *name, kfile_t *file, char *argv[]);
pid_t getpid();
pid_t getppid();
unsigned long sleep(unsigned long second);

/* vmm */
unsigned long heap(unsigned long heap);

/* device resource */
int writeres(int res, off_t off, void *buffer, size_t size);
int readres(int res, off_t off, void *buffer, size_t size);
int getres(char *name, unsigned long flags, unsigned long arg);
int putres(int res);
int ctlres(int res, unsigned int cmd, unsigned long arg);

int trigger(int trig, trighandler_t handler);
int trigger_action(int trig, trig_action_t *act, trig_action_t *oldact);
int triggeron(int trig, pid_t pid);

unsigned long alarm(unsigned long second);
unsigned long ktime(ktime_t *ktm);

#endif  /* _SYS_XCORE_H */
