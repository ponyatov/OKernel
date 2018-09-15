initialization
initialize
	| s |
	s := self class name asLowercase.
	tag := s copyFrom: 2 to: s size.
	val := nil.
	attr := Dictionary new.
	nest := OrderedCollection new.
	lastgen ifNil: [ lastgen := 0 ].
	ref := 0. gen := lastgen.
	ramstorage ifNil: [ ramstorage := OStorage new ].
	storage := ramstorage.