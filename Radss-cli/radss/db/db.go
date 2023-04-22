package db

import (
	"fmt"
	"log"
	"os"
	_ "radss/config"
	"radss/utils"

	"github.com/spf13/viper"
	"github.com/syndtr/goleveldb/leveldb"
	"github.com/syndtr/goleveldb/leveldb/opt"
)

var (
	DBClient *leveldb.DB
)

func init() {

	db, err := leveldb.OpenFile(viper.GetString("storage.path"), nil)

	if err != nil {
		log.Fatalln("Database connect error, please debug!", err)
		os.Exit(1)
	}

	DBClient = db
}

func GetStringKeyValue(key, predictValue string, cached bool) (val string, same bool) {
	valByte, err := DBClient.Get([]byte(key), &opt.ReadOptions{cached, 0})
	if err != nil {
		fmt.Println("Key : ", key, "has not been found")
	}
	if utils.BytesEqual(valByte, []byte(predictValue)) {
		same = true
		val = predictValue
	} else {
		same = false
		val = string(valByte)
	}
	return
}

func SetStringKeyValue(key, value string) (preValue string, exists bool) {
	exists, err := DBClient.Has([]byte(key), &opt.ReadOptions{false, 0})
	if err != nil {
		log.Fatalln(err)
	}
	if exists {
		preValueByte, err := DBClient.Get([]byte(key), &opt.ReadOptions{false, 0})
		if err != nil {
			log.Fatalln(err)
		}
		preValue = string(preValueByte)
	}
	err = DBClient.Put([]byte(key), []byte(value), &opt.WriteOptions{false, false})
	if err != nil {
		log.Fatalln(err)
	}
	return
}
