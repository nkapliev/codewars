//@see https://www.codewars.com/kata/pascals-triangle

function pascalsTriangle(n) {
	var items = [],
		fac = ((facs) => {
			return function _fac(x, y = 1) {
				return facs[x] ? facs[x] * y :
					(facs[x] = _fac(x - 1, x * y));
			};
		})({ 0: 1 });

	for (var i = 0; i < n; i++) {
		for (var j = 0; j <= i; j++) {
			items.push(Math.round(fac(i) / (fac(j) * fac(i - j))));
		}
	}

	return items;
}


console.log(pascalsTriangle(24));
