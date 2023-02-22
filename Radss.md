# Raft based Distributed Storage System

Distributed Consensus Algorithm : Raft

Storage Model : K-V, LSMTree, 

Client : RESTful API(Web 2.0 HTTP/HTTPS), CLI (Command Line Interface), RPC(gRPC over TCP) 



# CLI

{home_dir}/Radss-cli

````bash
go install github.com/spf13/cobra-cli@latest
go get -u github.com/spf13/cobra@latest
go get -u github.com/spf13/viper@latest
cobra-cli init radss
cobra-cli add query
cobra-cli add update

go get github.com/syndtr/goleveldb/leveldb
````



