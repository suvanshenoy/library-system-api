import { borrowBook, returnBook, getRecommendations } from './api';

async function main() {
  try {
    await borrowBook(1, 1);
    await returnBook(1, 1);
    const recommendations = await getRecommendations(1);
    console.log('Recommendations:', recommendations);
  } catch (error) {
    console.error(error);
  }
}

main();
