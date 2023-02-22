/*
Copyright © 2023 NAME HERE <chisato-x@qq.com>
*/
package cmd

import (
	"fmt"
	"os"
	_ "radss/config"
	"radss/def"

	"github.com/spf13/cobra"
	"github.com/spf13/viper"
)

// rootCmd represents the base command when called without any subcommands
var rootCmd = &cobra.Command{
	Use:   "radss",
	Short: def.RadssCLIShortComment,
	Long:  def.RadssCLILongComment,
	// Uncomment the following line if your bare application
	// has an action associated with it:
	Run: func(cmd *cobra.Command, args []string) {
		fmt.Println("😊 App Name is", viper.GetString("app.name"),
			", Author Name is", viper.GetString("author.name"),
			", Author Favor is", def.RadssAuthorFavor)
	},
}

func Execute() {
	err := rootCmd.Execute()
	if err != nil {
		os.Exit(1)
	}
}

func init() {

	rootCmd.PersistentFlags().StringP("author", "a", viper.GetString("author.name"), "Author Name")
	rootCmd.PersistentFlags().StringVarP(&def.RadssAuthorFavor, "favor", "f", viper.GetString("author.favor"), "Author Favor")
	viper.BindPFlag("author", rootCmd.Flags().Lookup("author"))
	viper.BindPFlag("favor", rootCmd.Flags().Lookup("favor"))

	rootCmd.AddCommand(queryCmd)
	queryCmd.PersistentFlags().BoolVarP(&def.RadssQueryMode, "mode", "m", true, "Query Mode")
	viper.BindPFlag("mode", rootCmd.Flags().Lookup("mode"))
	addQueryCmd()
}
