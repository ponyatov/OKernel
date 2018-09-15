printing
dump: depth prefix: prefix
	" dump object in full tree text form "
	| out |
	out := (String cr) , ( self pad: depth ) , ( self head: prefix ).
	" iterate over attr{}ibutes "
	attr keysAndValuesDo: [ :k :v | out := out , ( v
		dump: ( depth + 1 )
		prefix: (k , ' = ') )].
	" iterate over nest[]ed elements "
	nest do: [ :j | out := out , ( j dump: (depth +1) prefix: '' ) ] .
	" return result "
	^ out