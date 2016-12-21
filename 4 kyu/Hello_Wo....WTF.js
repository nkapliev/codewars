// @see https://www.codewars.com/kata/hello-w-dot-dot-dot-wait-what

var helloWorld = (() => {
    const zero = Number()
    const one = Number(!zero)
    const o = String(zero)
    const l = String(one)
    const codes = [
        l + o + o + l + o + o + o,
        l + l + o + o + l + o + l,
        l + l + o + l + l + o + o,
        l + l + o + l + l + o + o,
        l + l + o + l + l + l + l,
        l + o + o + o + o + o,
        l + o + l + o + l + l + l,
        l + l + o + l + l + l + l,
        l + l + l + o + o + l + o,
        l + l + o + l + l + o + o,
        l + l + o + o + l + o + o,
        l + o + o + o + o + l
    ]
    const letters = codes.map(code => parseInt(code, one + one))
    const phrase = String.fromCharCode.apply(String, letters)

    return () => phrase
})()
