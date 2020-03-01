# Ex. powershell -ExecutionPolicy RemoteSigned .\makedir.ps1 abc123
$contest_name = $Args[0]
mkdir $contest_name
$start = [byte][char]$Args[1]
$end = [byte][char]$Args[2]

$array = @()
for ($i = $start; $i -le $end; $i++) {
    $array += [char]$i
}
#$array = @("c","d","e","f")
#$array = @("a","b","c","d","e","f")
#$array = @("a", "b")
#$array = @("e", "f")
for ($i = 0; $i -lt $array.Count; $i++) {
    $name_diff = $array[$i]
#    Write-Output($name_diff)
    Copy-Item Template.cpp "${contest_name}/${contest_name}_${name_diff}.cpp"   
}