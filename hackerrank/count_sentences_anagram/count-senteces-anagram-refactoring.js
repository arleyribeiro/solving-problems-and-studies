'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}



/*
 * Complete the 'countSentences' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY wordSet
 *  2. STRING_ARRAY sentences
 */

function countSentences(wordSet, sentences) {
    const numberOfAnagramsOrdered = countNumberOfAnagramsOrdered(wordSet);
    return sentences.map((sentence) => {
        return (sentence.split(' ') || []).reduce((numberOfSenteces, word) => {
            const _word = sortAlphabets(word);
            const numberAnagrams = numberOfAnagramsOrdered[_word];
            if (numberAnagrams) {
                numberOfSenteces = numberOfSenteces * numberAnagrams;
            }
            return numberOfSenteces;
        }, 1);
    });
}

var sortAlphabets = function(text) {
    return text.split('').sort().join('');
};

function countNumberOfAnagramsOrdered(wordSet) {
    const wordOredered = {};
    wordSet.map((word) => {
        const ordered = sortAlphabets(word);
        if (!wordOredered[ordered]) {
            wordOredered[ordered] = 1;
        } else {
            wordOredered[ordered]++;
        }
        return ordered;
    });
    return wordOredered;
}

function main() {
    //const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const wordSetCount = parseInt(readLine().trim(), 10);

    let wordSet = [];

    for (let i = 0; i < wordSetCount; i++) {
        const wordSetItem = readLine();
        wordSet.push(wordSetItem);
    }

    const sentencesCount = parseInt(readLine().trim(), 10);

    let sentences = [];

    for (let i = 0; i < sentencesCount; i++) {
        const sentencesItem = readLine();
        sentences.push(sentencesItem);
    }

    const result = countSentences(wordSet, sentences);
    console.log(result.join('\n') + '\n')

    //ws.write(result.join('\n') + '\n');

    //ws.end();
}
