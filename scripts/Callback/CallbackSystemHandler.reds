// The game declares these with gameCallbackRunMode/gameCallbackLifetime, which have the same values.

@addMethod(CallbackSystemHandler)
public native func SetRunMode(runMode: CallbackRunMode) -> ref<CallbackSystemHandler>

@addMethod(CallbackSystemHandler)
public native func SetLifetime(lifetime: CallbackLifetime) -> ref<CallbackSystemHandler>
