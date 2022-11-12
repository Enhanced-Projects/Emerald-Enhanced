#include "callback_utils.h"
#include "global.h"
#include "malloc.h"
#include "main.h"
#include "overworld.h"

struct AdditiveCallback gAdditiveCallback;

void RunAdditveCallbacks(struct AdditiveCallback* current) {
    if (current->mainCallback)
        current->mainCallback();
    if (current->secondCallback)
        current->secondCallback();
}

void RunAdditiveCallbacksLoop(void) {
    struct AdditiveCallback* current;
    current = &gAdditiveCallback;
    RunAdditveCallbacks(current);
    while (current->child) {
        current = current->child;
        RunAdditveCallbacks(current);
    }
}

void ResetCallbacks(void) {
    struct AdditiveCallback* current = gAdditiveCallback.child;
    while (current) {
        current = current->child;
        free(current);
    }
    gAdditiveCallback.mainCallback = NULL;
    gAdditiveCallback.secondCallback = NULL;
    gAdditiveCallback.child = NULL;
}

void ResetToMainCallback(void) {
    gMain.callback1 = gAdditiveCallback.mainCallback;
    gMain.state = 0;
}

void ResetToOverworldMainCallback(void) {
    gMain.callback1 = CB1_Overworld;
    gMain.state = 0;
}