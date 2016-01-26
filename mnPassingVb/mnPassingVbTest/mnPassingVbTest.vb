'Copyright © exc-jdbi 2016

'© mnPassing 2016

'mnPassing - www.github.com/exc-jdbi/passing

'mnPassing is Free and Opensource Software

Option Strict On
Option Explicit On
Imports TestDll
Module mnPassingVbTest
    Sub Main()
        Dim pass As New vbPassing
        Dim min As Integer = 16
        Dim max As Integer = 64
        Dim size As Integer = 10

        Dim lst = pass.getRndPasswortList(size, min, max)        
        pass.Close()
        Stop
    End Sub
End Module
