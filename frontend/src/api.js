import axios from 'axios';
import dotenv from 'dotenv';

dotenv.config()
const API_BASE_URL = process.env.API_BASE_URL;

export const borrowBook = async (userId: number, bookId: number): Promise<void> => {
  try {
    const response = await axios.post(`${API_BASE_URL}/borrow`, null, {
      params: { userId, bookId },
      headers: { 'Content-Type': 'text/plain' }
    });
    console.log(response.data);
  } catch (error) {
    console.error('Error borrowing book:', error.response?.data || error.message);
  }
}

export const returnBook = async (userId: number, bookId: number): Promise<void> => {
  try {
    const response = await axios.post(`${API_BASE_URL}/return`, null, {
      params: { userId, bookId },
      headers: { 'Content-Type': 'text/plain' }
    });
    console.log(response.data);
  } catch (error) {
    console.error('Error returning book:', error.response?.data || error.message);
  }
}

export const getRecommendations = async (userId: number): Promise<any> => {
  try {
    const response = await axios.get(`${API_BASE_URL}/recommendations`, {
      params: { userId }
    });
    return response.data;
  } catch (error) {
    console.error('Error getting recommendations:', error.response?.data || error.message);
    return [];
  }
}
