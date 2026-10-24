// CallbackSystem is declared by the game since 2.5. Its RegisterStaticCallback takes the target as an object, so the
// Codeware signature is added as an overload. Both bind to the same native, which expects a class name.

@addMethod(CallbackSystem)
public native func RegisterStaticCallback(eventName: CName, target: CName, function: CName, opt sticky: Bool) -> ref<CallbackSystemHandler>
