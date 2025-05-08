
//windows
{
"shell_cmd": "g++.exe -std=c++17 \"$file\" -o \"$file_base_name\".exe && \"$file_base_name.exe\"<\"D://c programes/in.txt\">\"D://c programes/out.txt\"",
"shell":true,
"working_dir":"$file_path",
"selector":"source.c, source.cpp, source.c++"
}


//linux
{
"cmd" : ["g++ -std=c++17 \"$file_name\" && timeout 10s ./a.out <~/Code/input.txt | head -n 2000000 | head -c 50000000 >~/Code/output.txt"], 
"selector" : "source.c,source.cpp,source.c++",
"shell": true,
"working_dir" : "$file_path"
}

