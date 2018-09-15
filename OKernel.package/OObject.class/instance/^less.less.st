adding
<< anOMethod 
	omethod at: anOMethod oselector put: anOMethod.
	anOMethod usein: self. self uses: anOMethod.
	^ self