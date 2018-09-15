printing
head: prefix
	" dump object in short head-only form "
	^ prefix , '<' , tag , ':' , val asString , '>'