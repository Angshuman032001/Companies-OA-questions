## Statement

![](https://assets.leetcode.com/users/images/6a082db3-9fb1-4f95-aab0-2e5a2b55401b_1670865378.2583287.jpeg)
![](https://assets.leetcode.com/users/images/a1599d42-0342-4109-ab76-00de707157a9_1670865403.6092064.jpeg)


## Solution

```python
def solve(messages, width, userWidth):
    messengerWindow = ['+' + '*' * width + '+']
    currentLine = ''
    for user, message in messages:
        words = message.split()
        for idx, word in enumerate(words):
            if not currentLine:
                currentLine += word
            else:
                currentLine += ' ' + word
            if idx == len(words) - 1 or len(words[idx + 1]) + len(currentLine) >= userWidth:
                if user == 1:
                    currentLine = '|' + currentLine.ljust(width, ' ') + '|'
                    messengerWindow.append(currentLine)
                else:
                    currentLine = '|' + currentLine.rjust(width, ' ') + '|'
                    messengerWindow.append(currentLine)
                currentLine = ''

    messengerWindow += ['+' + '*' * width + '+']
    return messengerWindow
```
