function sleep(ms) {
  return new Promise((resolve) => setTimeout(resolve, ms));
}

async function demoSleep() {
  console.log("Zzz...");
  await sleep(1000);
  console.log("Beep beep beep!");
}

demoSleep();

const data = await fetchDataFromAPI();

fetchDataFromAPI()
  .then((data) => processData(data))
  .then((result) => console.log(result));

async function makeAPICalls() {
  for (let i = 0; i < 5; i++) {
    await callAPI();
    await sleep(1000);
  }
}

async function fetchDataWithRetry(url, retries) {
  for (let i = 0; i < retries; i++) {
    try {
      const data = await fetch(url);
      return data;
    } catch (error) {
      if (i < retries - 1) {
        await sleep(2000);
      } else {
        throw error;
      }
    }
  }
}

async function animate() {
  for (let i = 0; i < 10; i++) {
    renderFrame(i);
    await sleep(100);
  }
}
