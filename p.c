body {
    font-family: 'Arial', sans-serif;
    display: flex;
    align-items: center;
    justify-content: center;
    height: 100vh;
    margin: 0;
}

.sudoku-board {
    display: grid;
    grid-template-columns: repeat(9, 40px);
    grid-template-rows: repeat(9, 40px);
    gap: 1px;
}

.cell {
    width: 40px;
    height: 40px;
    text-align: center;
    font-size: 1.2em;
    border: 1px solid #000;
}

/* Add styling