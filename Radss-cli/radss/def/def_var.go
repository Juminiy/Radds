package def

import "context"

var (
	// base setter
	RadssAuthorName  string
	RadssAuthorEmail string
	RadssAuthorFavor string
	RadssAppName     string
	RadssAppVersion  string
	RadssStorageURL  string
	RadssStoragePath string
	// nosql, sql
	RadssQueryMode string
	// gpt setter
	RadssAskGPTAPIKEY        string
	RadssAskGPTSystemContent string
	RadssAskGPTUserContent   string
	Ctx                      = context.Background()
)

