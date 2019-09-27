param(
  [string] $gdk_home = (get-item "$($PSScriptRoot)").parent.FullName, ## The root of the UnrealGDK repo
  [string] $gcs_publish_bucket = "io-internal-infra-unreal-artifacts-production/UnrealEngine",
  [string] $msbuild_exe = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\2017\BuildTools\MSBuild\15.0\Bin\MSBuild.exe",
  [string] $target_platform = "Win64"
)

. "$PSScriptRoot\common.ps1"

# Download Unreal Engine
Start-Event "get-unreal-engine" "command"
&$PSScriptRoot"\get-engine.ps1"
Finish-Event "get-unreal-engine" "command"

# Run the required setup steps
Start-Event "setup-gdk" "command"
&$PSScriptRoot"\setup-gdk.ps1"
Finish-Event "setup-gdk" "command"

# # Build the GDK plugin
# Start-Event "build-gdk" "command"
# &$PSScriptRoot"\build-gdk.ps1" -target_platform $($target_platform)
# Finish-Event "build-gdk" "command"

# Write-Log "built plugin is at $($gdk_home)/SpatialGDK/Intermediate/BuildPackage/Win64"
# Write-Log "built plugin folder contents: $(Get-ChildItem $gdk_home/SpatialGDK/Intermediate/BuildPackage/Win64)"

# $unreal_path = "$($gdk_home)\UnrealEngine"

# Start-Event "setup-tests" "command"
# &$PSScriptRoot"\setup-tests.ps1" -project_clone_path "$($unreal_path)\Samples"
# Finish-Event "setup-tests" "command"

# Start-Event "test-gdk" "command"
# &$PSScriptRoot"\run-tests.ps1" -ue_path "$($unreal_path)\Engine\Binaries\Win64\UE4Editor.exe" -uproject_path "$($unreal_path)\Samples\UnrealGDKExampleProject\Game\GDKShooter.uproject" -output_dir "TestResults" -log_file_name "tests.log"
# Finish-Event "test-gdk" "command"
