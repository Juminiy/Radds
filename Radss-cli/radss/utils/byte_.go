package utils

func BytesEqual(comp, comped []byte) bool {
	if comp == nil && comped == nil {
		return true 
	}
	comp_len, comped_len := len(comp), len(comped)
	if comp_len != comped_len {
		return false 
	} 
	for i := 0; i < comp_len; i ++ {
		if comp[i] != comped[i] {
			return false 
		}
	}
	return true 
}