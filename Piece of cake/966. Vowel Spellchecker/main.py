class Solution:
    def spellchecker(self, wordlist: [str], queries: [str]) -> [str]:
        res = []
        origin = set()
        lowercase, vowels = {}, {}
        for w in wordlist:
            origin.add(w)
            lw = w.lower()
            if lw not in lowercase:
                lowercase[lw] = w
                for ch in 'aeiou':
                    lw = lw.replace(ch, '#')
                if lw not in vowels:
                    vowels[lw] = w
        for q in queries:
            if q in origin:
                res.append(q)
                continue
            q = q.lower()
            if q in lowercase:
                res.append(lowercase[q])
                continue
            for ch in 'aeiou':
                q = q.replace(ch, '#')
            if q in vowels:
                res.append(vowels[q])
                continue
            res.append('')
        return res

    # 题意理解错了。
    def spellchecker_WA(self, wordlist: [str], queries: [str]) -> [str]:
        res = []
        origin = set()
        lowercase, vowels = {}, {}
        for idx, w in enumerate(wordlist):
            origin.add(w)
            lw = w.lower()
            if lw not in lowercase:
                lowercase[lw] = w
                for i in range(len(lw)):
                    if lw[i] in 'aeiou':
                        vw = lw[:i] + '#' + lw[i + 1:]
                        vowels[vw] = idx
        print(origin)
        print(lowercase)
        print(vowels)
        for q in queries:
            if q in origin:
                res.append(q)
                continue
            q = q.lower()
            if q in lowercase:
                res.append(lowercase[q])
                continue

            cand = []
            for i in range(len(q)):
                if q[i] in 'aeiou':
                    vq = q[:i] + '#' + q[i + 1:]
                    print(f'vq:{vq}')
                    if vq in vowels:
                        cand.append(vowels[vq])
                
            if cand:
                res.append(wordlist[min(cand)])
            else:
                res.append('')
        return res

s1 = Solution()
t = s1.spellchecker(["KiTe","kite","hare","Hare"], ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"])
print(t)