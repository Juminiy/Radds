package cmd

import (
	"errors"
	"fmt"
	"io"
	"log"
	_ "radss/config"
	"radss/def"

	gogpt "github.com/sashabaranov/go-gpt3"
	"github.com/spf13/cobra"
)

var GPTCmd = &cobra.Command{
	Use:     "ask",
	Short:   "Ask me whatever you want!",
	Long:    "Ask me whatever you wanna to ask!",
	Example: "radss ask -s \"你是一个数据库科学家\" -u \"什么叫做分布式数据库\" -k \"OpenAI API KEY\" ",
	Run: func(cmd *cobra.Command, args []string) {
		if len(def.RadssAskGPTAPIKEY) == 0 {
			log.Fatalln("OpenAI API KEY in os env search failed, in config file search failed, in command flags search failed.")
			return
		}
		c := gogpt.NewClient(def.RadssAskGPTAPIKEY)

		msgs := make([]gogpt.ChatCompletionMessage, 2)
		msgs[0].Role = "system"
		msgs[0].Content = def.RadssAskGPTSystemContent
		msgs[1].Role = "user"
		msgs[1].Content = def.RadssAskGPTUserContent

		req := gogpt.ChatCompletionRequest{
			Model:    gogpt.GPT3Dot5Turbo,
			Messages: msgs,
			Stream:   true,
		}
		respStream, err := c.CreateChatCompletionStream(def.Ctx, req)
		if err != nil {
			return
		}
		defer respStream.Close()
		for {
			resp, err := respStream.Recv()
			if errors.Is(err, io.EOF) {
				fmt.Println("我结束了回答")
				return
			}
			if err != nil {
				log.Fatalln("Stream error:", err)
				return
			}

			fmt.Print(resp.Choices[0].Delta.Content)
		}
	},
}
