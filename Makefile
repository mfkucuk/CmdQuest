
main:
	g++ -DCMDQUEST_EXPORTS -shared -o Sandbox/CmdQuest.dll src/*.cpp -Wl,--out-implib,Sandbox/src/lib/libCmdQuest.a
	g++ -ISandbox/src/include -LSandbox/src/lib Sandbox/*.cpp -o Sandbox/main -lCmdQuest && .\Sandbox\main

build:
	g++ -DCMDQUEST_EXPORTS -shared -o bin/CmdQuest.dll src/*.cpp -Wl,--out-implib,bin/lib/libCmdQuest.a

sandbox:
	g++ -DCMDQUEST_EXPORTS -shared -o Sandbox/CmdQuest.dll src/*.cpp -Wl,--out-implib,Sandbox/src/lib/libCmdQuest.a