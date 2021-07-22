import express from 'express';
import SerialPort from 'serialport';
import path from 'path';

const app = express();
const port = 3000;

const serialPort = new SerialPort('COM3', {
    baudRate: 9600,
    autoOpen: false
});

app.use('/images', express.static(path.join(__dirname, 'images')));

app.get('/', async (req, res) => {
    res.sendFile(path.join(__dirname, 'static/index.html'))
});

app.post('/open', (req, res) => {

    serialPort.open((err) => {
        if (err) {
            res.send('Port is busy!');
        }
        serialPort.write('OPEN', (err, bw) => {
            if (err) {
                serialPort.close();
                res.send('Port write error');
            }
            serialPort.close();
            res.send('Opened successfully');
        });
    });

});

app.get('/get-paths', async (req, res) => {
    res.send(await SerialPort.list());
});

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`)
});
