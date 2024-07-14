def fill_speech(speech: str, letters: int) -> str:
    for i in range(letters):
        speech += chr(66 + i)
    return speech


n, k = [int(i) for i in input().split()]
palindrome = 'A' * k

rest_of_speech = ''
length_of_rest = min(25, n - k)
rest_of_speech = fill_speech(rest_of_speech, length_of_rest)

length_of_rest = max(n - k - length_of_rest, 0)
rest_of_speech = fill_speech(rest_of_speech, length_of_rest)

print(palindrome + rest_of_speech)
