/*
Copyright © 2023 NAME HERE <chisato-x@qq.com>
*/
package cmd

import (
	"fmt"
	_ "radss/config"
	"radss/db"
	"radss/def"

	"github.com/spf13/cobra"
)

// queryCmd represents the query command
var queryCmd = &cobra.Command{
	Use:   "query",
	Short: def.QueryCLIShortComment,
	Long:  def.QueryCLILongComment,
}

var queryGetCmd = &cobra.Command{
	Use:     "get",
	Short:   "Get command",
	Long:    "Get command receive two parameters at most, one is [key], another is [predict_value](exception)",
	Example: "radss -a neuq query -m nosql get k1 v1",
	Run: func(cmd *cobra.Command, args []string) {
		val := ""
		if len(args) == 1 {
			val, _ = db.GetStringKeyValue(args[0], "", true)
		} else if len(args) == 2 {
			val, _ = db.GetStringKeyValue(args[0], args[1], true)
		} else {
			fmt.Println("Parameter is expected to 1 or 2, received", len(args))
		}
		if len(val) > 0 && val != "" {
			fmt.Println(val)
		}
	},
}

var querySetCmd = &cobra.Command{
	Use:     "set",
	Short:   "Set command",
	Long:    "Set command only receive two parameters, one is [key], another is [value]",
	Example: "radss -a neuq query -m nosql set k1 v2",
	Run: func(cmd *cobra.Command, args []string) {
		if len(args) == 2 {
			preValue, exists := db.SetStringKeyValue(args[0], args[1])
			if exists {
				if preValue == args[1] {
					fmt.Println("Value unchanged")
				} else {
					fmt.Println("Value updated")
				}
			} else {
				fmt.Println("(", args[0], ",", args[1], ") has setted")
			}
		} else {
			fmt.Println("Parameter is expected to 2, received", len(args))
		}

	},
}

func addQueryCmd() {
	queryCmd.AddCommand(queryGetCmd)
	queryCmd.AddCommand(querySetCmd)
}
