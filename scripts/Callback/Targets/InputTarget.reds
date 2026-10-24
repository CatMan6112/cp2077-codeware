// The game declares Key(key, opt threshold: Float). This overload keeps Codeware's action argument; the parameter
// keeps the game's name because the game merges declarations of the same native by parameter name.

@addMethod(InputTarget)
public static native func Key(key: EInputKey, threshold: EInputAction) -> ref<InputTarget>
