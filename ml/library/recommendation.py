# venv: site-packages
# r: numpy
# r: pandas

import pandas as pd
from sklearn.neighbors import NearestNeighbors
from typing import List

class RecommendationSystem:
    def __init__(self):
        self.data = pd.DataFrame({
            'user_id': [1, 2, 3, 4],
            'book_id': [1, 1, 2, 2],
            'rating': [5, 4, 5, 4]
        })
        self.model = NearestNeighbors(metric='cosine', algorithm='brute')
        self.model.fit(self.data.pivot(index='user_id', columns='book_id', values='rating').fillna(0))

    def recommend(self, user_id: int) -> List[int]:
        user_data = self.data[self.data['user_id'] == user_id]
        if user_data.empty:
            return []

        user_vector = user_data.pivot(index='user_id', columns='book_id', values='rating').fillna(0)
        distances, indices = self.model.kneighbors(user_vector, n_neighbors=3)
        
        recommendations = []
        for i in indices.flatten():
            recommendations.append(self.data.loc[i, 'book_id'])
        
        return recommendations

