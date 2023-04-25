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



golang的加载顺序：pkg->dir_pkg->const->var->>init()

# API

RESTful API

# Panel

control panel

# SDB

database-interface

# Core

## RPC

C++需要CMakelists.txt, gRPC需要Linux,校园网与虚拟化网卡冲突，关闭Hyper-V，重启windows

````bash
# admin ps
# close
bcdedit /set hypervisorlaunchtype off
# recover 
bcdedit /set hypervisorlaunchtype auto
````



## Raft

## Data
字符指针 Slice : char* data_, size_t size_;

## Storage

### Memory

SDS：Simple Dynamic String 

```bash
LPUSH fruit banana apple pea
```

"fruit"是一个sds对象，"banana" "apple" "pea"分别是一个sds对象

