/*
Copyright © 2023 NAME HERE <EMAIL ADDRESS>
*/
package cmd

import (
	"fmt"
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
	Long:    "Get commande only receive two parameter, one is [key], another is [value]",
	Example: "radss -a \"hln\" query -m true get k1 v1",
	Run: func(cmd *cobra.Command, args []string) {
		val, _ := db.GetStringKeyValue(args[0], args[1], true)
		fmt.Println(val)
	},
}

func addQueryCmd() {
	queryCmd.AddCommand(queryGetCmd)
}
