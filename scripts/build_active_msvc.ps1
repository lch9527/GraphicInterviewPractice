param(
    [Parameter(Mandatory = $true)][string]$WorkspaceFolder,
    [Parameter(Mandatory = $true)][string]$FilePath,
    [Parameter(Mandatory = $true)][string]$FileDir,
    [Parameter(Mandatory = $true)][string]$FileBaseNameNoExtension
)

$ErrorActionPreference = "Stop"

$buildDir = Join-Path $WorkspaceFolder "build"
if (!(Test-Path $buildDir)) {
    New-Item -ItemType Directory -Path $buildDir | Out-Null
}

$pf86 = ${env:ProgramFiles(x86)}
if (-not $pf86) {
    throw "ProgramFiles(x86) environment variable is missing."
}

$vswhere = Join-Path $pf86 "Microsoft Visual Studio\Installer\vswhere.exe"
if (!(Test-Path $vswhere)) {
    throw "vswhere.exe not found. Install Visual Studio 2022 Build Tools with C++."
}

$vsDevCmd = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -find "Common7\Tools\VsDevCmd.bat"
if (-not $vsDevCmd) {
    throw "MSVC toolchain not found. Install Desktop development with C++ workload."
}

$includeDir = Join-Path $FileDir "..\include"
$outExe = Join-Path $buildDir ($FileBaseNameNoExtension + ".exe")
$outObj = Join-Path $buildDir ($FileBaseNameNoExtension + ".obj")

$cmdLine = "`"$vsDevCmd`" -arch=x64 -host_arch=x64 && cl /std:c++17 /EHsc /nologo /I`"$includeDir`" `"$FilePath`" /Fe:`"$outExe`" /Fo:`"$outObj`""
cmd /c $cmdLine
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}
