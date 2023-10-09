/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function (matrix) {
    let n = matrix.length;
    let m = matrix[0].length;
    let row = new Array(n).fill(false);
    let col = new Array(m).fill(false);
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (let i = 0; i < n; i++) {
        if (row[i] == true) {
            for (let j = 0; j < m; j++) {
                matrix[i][j]=0;
            }
        }
    }
    for (let j = 0; j < m; j++) {
        if (col[j] == true) {
            for (let i = 0; i < n; i++) {
                matrix[i][j]=0;
            }
        }
    }
};