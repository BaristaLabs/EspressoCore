namespace BaristaLabs.EspressoCore.JavaScript.Native
{
    using System.Runtime.InteropServices;

    public static class V8
    {
        [DllImport(Loader.DllName, EntryPoint = "Initialize", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Initialize([MarshalAs(UnmanagedType.LPStr)] string directoryPath = "");

        /// <summary>
        /// Clears all references to the v8::Platform. This should be invoked after V8 was disposed.
        /// </summary>
        /// <returns></returns>
        [DllImport(Loader.DllName, EntryPoint = "Shutdown", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Shutdown();
    }
}
