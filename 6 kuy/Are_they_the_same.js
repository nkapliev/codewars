// @see https://www.codewars.com/kata/550498447451fbbd7600041c

function comp(array1, array2) {
	if ( ! array1 || ! array2 || array1.length !== array2.length) {
		return false;
	} else if (array1.length === 0) {
		return true;
	} else {
		array1.sort((a, b) => { return a - b; });
		array2.sort((a, b) => { return a - b; });

		return array1.every((e, i) => {
			return e * e === array2[i];
		});
	}
}
