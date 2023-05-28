package db_test

import (
	"fmt"
	"log"
	"os"
	"radss/db"
	"testing"

	"github.com/syndtr/goleveldb/leveldb"
)

func TestLevelDB(t *testing.T) {
	db, err := leveldb.OpenFile("/tmp/dbfile/leveldb", nil)
	defer db.Close()
	if err != nil {
		log.Fatalln(err)
		os.Exit(1)
	}
	// defer db.Close()
	val, _ := db.Get([]byte("k1"), nil)
	fmt.Println(val)
	db.Put([]byte("k1"), []byte("v1"), nil)
	fmt.Println(val)
	val, _ = db.Get([]byte("k1"), nil)
	fmt.Println(val)
}

func TestDBClient(t *testing.T) {
	key, value := "k1", "v1"
	val, _ := db.GetStringKeyValue(key, value, true)
	t.Log(val)
	val, _ = db.SetStringKeyValue(key, value)
	t.Log(val)
}
