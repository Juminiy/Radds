package config

import (
	"log"
	"os"
	"radss/def"

	"github.com/spf13/viper"
)

func init() {
	viper.AddConfigPath(".")
	viper.AddConfigPath("../")
	viper.SetConfigName(def.RadssConfigFileName)
	viper.SetConfigType(def.RadssConfigFileType)
	HandleConfigErr()
	configOpenAIAPIKEY()
}

func configOpenAIAPIKEY() {
	osOpenAiApiKey := os.Getenv("OPENAI_API_KEY")
	// fmt.Println(osOpenAiApiKey)
	// os
	if len(osOpenAiApiKey) != 0 {
		def.RadssAskGPTAPIKEY = osOpenAiApiKey
	}
	// config_file
	configOpenAiApiKey := viper.GetString("openai.gpt.apikey")
	if len(configOpenAiApiKey) != 0 {
		def.RadssAskGPTAPIKEY = configOpenAiApiKey
	}
}

func HandleConfigErr() {
	if err := viper.ReadInConfig(); err != nil {
		if _, ok := err.(viper.ConfigFileNotFoundError); ok {
			log.Fatalln("Config file", def.RadssConfigFileName+"."+def.RadssConfigFileType, "has not been found!", "Please use the command `touch radss-cli.yml` to create the file.")
			os.Exit(1)
		} else {
			log.Fatalln("Config file meet other troubles, please debug!")
		}
	}

}
