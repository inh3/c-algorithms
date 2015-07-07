#include <stdio.h>
#include <stdint.h>
#include <string.h>

void replaceSpacesInSentence(char sentenceBuffer[1024]);

int main() {

    const char *sentence = " This is a test sentence. ";
    char sentenceBuffer[1024] = { 0 };
    memcpy(sentenceBuffer, sentence, strlen(sentence));

    printf("REPLACE SPACES: %lu\n", sizeof(sentenceBuffer)/sizeof(sentenceBuffer[0]));
    printf("Original: %s\n", sentenceBuffer);
    replaceSpacesInSentence(sentenceBuffer);
    printf("Replaced: %s\n", sentenceBuffer);

    return 0;
}

// replacing ' ' with '%20'
void replaceSpacesInSentence(char buffer[1024]) {

    // the offset is 1 less than than the length because the existing
    // space takes up one slot already
    const char* spaceReplacement = "%20";
    uint32_t replacementOffset = strlen(spaceReplacement) - 1;

    uint32_t wordLength = strlen(buffer);

    // count the number of spaces
    uint32_t numSpaces = 0;
    for(uint32_t i = 0; i < wordLength; i++) {
        if(buffer[i] == ' ')
            numSpaces++;
    }

    // work backward through the string and move each
    // non-space to the right the number of remaining spaces
    for(uint32_t j = wordLength; j >= 0; j--) {

        // not a space so copy the character over to the right
        if(buffer[j] != ' ') {
            buffer[j + numSpaces * replacementOffset] = buffer[j];
        }
        // space is found so need to replace the space
        else {
            // we've already moved characters to the right over far enough for all remaining spaces
            //
            // when we replace the current space we only need to account for the
            // spaces to the left, that is why we decrement first
            numSpaces--;
            uint32_t offset = replacementOffset * numSpaces;
            memcpy(&(buffer[j + offset]), spaceReplacement, strlen(spaceReplacement));

            // without memcpy(...)
            // buffer[j + offset] = '%';
            // buffer[j + offset + 1] = '2';
            // buffer[j + offset + 2] = '0';
        }

        // there aren't anymore spaces so we are done
        if(numSpaces == 0)
            break;
    }
}
