namespace BaristaLabs.EspressoCore.JavaScript.Native
{
    using System.Runtime.InteropServices;

    public static class JsEngine
    {
        [DllImport(Loader.DllName, EntryPoint = "EvaluateScript", CallingConvention = CallingConvention.Cdecl)]
        public static extern int EvaluateScript([MarshalAs(UnmanagedType.LPWStr)] string directoryPath = "");
    }
}
