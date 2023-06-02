function Get-AppAUMID {
param (
[string]$AppName
)
$Apps = (New-Object -ComObject Shell.Application).NameSpace('shell:::{4234d49b-0245-4df3-b780-3893943456e1}').Items()
if ($AppName){
    $Result = $Apps | Where-Object { $_.name -like "*$AppName*" } | Select-Object name,@{n="AUMID";e={$_.path}}
        if ($Result){
            Return $Result
        }
    else {"Unable to locate {0}" -f $AppName}
}
else {
    $Result = $Apps | Select-Object name,@{n="AUMID";e={$_.path}}
    Return $Result
}
}


# Get the AUMID for OneDrive
Get-AppAUMID -AppName WhatsApp