#ifndef _H_GUARD_CALLBACK_UTILS_
#define _H_GUARD_CALLBACK_UTILS_

typedef void (*MainCallback1)(void);
struct AdditiveCallback {
    MainCallback1 mainCallback;
    MainCallback1 secondCallback;
    struct AdditiveCallback* child;
};

extern struct AdditiveCallback gAdditiveCallback;

void RunAdditveCallbacks(struct AdditiveCallback* current);

void RunAdditiveCallbacksLoop(void);
void ResetCallbacks(void);
void ResetToMainCallback(void);
void ResetToOverworldMainCallback(void);
#endif