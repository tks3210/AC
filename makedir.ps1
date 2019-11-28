# Ex. powershell -ExecutionPolicy RemoteSigned .\makedir.ps1 abc123
$contest_name = $Args[0]
mkdir $contest_name
$array = @("a","b","c","d","e","f")
for ($i = 0; $i -lt $array.Count; $i++) {
    $name_diff = $array[$i]
    Copy-Item Template.cpp "${contest_name}/${contest_name}_${name_diff}.cpp"   
}