'Copyright © exc-jdbi 2016

'© mnPassing 2016

'mnPassing - www.github.com/exc-jdbi/passing

'mnPassing is Free and Opensource Software

Option Strict On
Option Explicit On
Imports System.Runtime.InteropServices
Public Class vbPassing
    Public Function Open() As Boolean
        Return dll.startGarbage()
    End Function
    Public Function Close() As Boolean
        Return dll.closeGarbage()
    End Function
    Public Function getRndPasswortList(ByVal size As Integer, ByVal min As Integer, ByVal max As Integer) As List(Of String)
        getRndPasswortList = Nothing
        Dim p1 As IntPtr = IntPtr.Zero, p2 As IntPtr = IntPtr.Zero
        Try
            Dim lst As List(Of String)
            Dim resSize As Integer = dll.getPwArray(size, min, max, p1, p2)
            If resSize > 0 Then
                lst = New List(Of String)(resSize)
                Dim s() As Char = {}
                Dim p0 As IntPtr = IntPtr.Zero
                Dim p00 As IntPtr = IntPtr.Zero
                Dim pT As IntPtr = IntPtr.Zero
                For i As Integer = 0 To resSize - 1
                    p0 = Marshal.ReadIntPtr(p1, i * Marshal.SizeOf(GetType(IntPtr)))
                    p00 = Marshal.ReadIntPtr(p2, i * Marshal.SizeOf(GetType(Integer)))
                    ReDim s(CInt(p00) - 1)
                    Marshal.Copy(p0, s, 0, CInt(p00))
                    lst.Add(s)
                    'Marshal.FreeCoTaskMem(p0)
                    Marshal.FreeCoTaskMem(p00)
                Next
                Return lst
            End If
        Catch ex As Exception
            Console.Write("Error: " & ex.Message)
        Finally
            'Marshal.FreeHGlobal(p1)
            'Marshal.FreeHGlobal(p2)
        End Try
    End Function
    Private MustInherit Class dll
        Const dllPathConfDebug As String = "../../../../mnPassingCpp/mnPassingTest/Debug/mnPassing.dll"
        Const dllPathConfRelease As String = "../../../../mnPassingCpp/mnPassingTest/Release/mnPassing.dll"

        Const dllPath = dllPathConfDebug
        <DllImport(dllPath)> _
        Public Shared Function startGarbage() As Boolean
        End Function
        <DllImport(dllPath)> _
        Public Shared Function closeGarbage() As Boolean
        End Function
        <DllImport(dllPath, CharSet:=CharSet.Unicode, CallingConvention:=CallingConvention.StdCall)> _
        Public Shared Function getPwArray(ByVal iSize As Integer, ByVal iMin As Integer, ByVal iMax As Integer, ByRef pPw As IntPtr, ByRef pXlen As IntPtr) As Integer
        End Function
    End Class
End Class
