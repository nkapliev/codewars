# @see: https://www.codewars.com/kata/decode-the-morse-code
def decodeMorse(morseCode):
    return ' '.join(
        map(lambda m_word: ''.join(
                map(lambda m_symbol: MORSE_CODE[m_symbol],
                    m_word.split())),
            morseCode.strip().split('   ')))

