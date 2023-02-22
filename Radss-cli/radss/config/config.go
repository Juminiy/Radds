package config

import (
	"log"
	"os"
	"radss/def"

	"github.com/spf13/viper"
)

func init() {
	viper.AddConfigPath(".")
	viper.SetConfigName(def.RadssConfigFileName)
	viper.SetConfigType(def.RadssConfigFileType)
	HandleConfigErr()
}

func HandleConfigErr() {
	if err := viper.ReadInConfig(); err != nil {
		if _, ok := err.(viper.ConfigFileNotFoundError); ok {
			log.Fatalln("Config file", def.RadssConfigFileName+"."+def.RadssConfigFileType, "has not been found!")
			os.Exit(1)
		} else {
			log.Fatalln("Config file meet other troubles, please debug!")
		}
	}

}
