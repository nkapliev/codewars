// @see https://www.codewars.com/kata/the-observed-pin

function getPINs(observed) {
	const DIGIT_VARIATIONS = {
		'0': [ '0', '8' ],
		'1': [ '1', '2', '4' ],
		'2': [ '2', '1', '3', '5' ],
		'3': [ '3', '2', '6' ],
		'4': [ '4', '1', '5', '7' ],
		'5': [ '5', '4', '2', '6', '8' ],
		'6': [ '6', '3', '5', '9' ],
		'7': [ '7', '4', '8' ],
		'8': [ '8', '5', '9', '7', '0' ],
		'9': [ '9', '6', '8' ]
	};

	return (function _getPINs(observed) {
		if (observed.length == 1) return DIGIT_VARIATIONS[observed].slice();

		var PINs = _getPINs(observed.slice(1));

		return DIGIT_VARIATIONS[observed[0]]
			.reduce(function(result, digit) {
				PINs.forEach(function(PIN) {
					result.push(digit + PIN);
				});

				return result;
			}, []);
	})(observed);
}
