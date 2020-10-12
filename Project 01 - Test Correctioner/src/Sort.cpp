#include "Sort.h"

int Sort::partition_best_candidates(Candidate* candidates, int left, int right) {
  int pivot_pos = left;
  Candidate pivot = candidates[pivot_pos];

  while (left < right) {
    while (candidates[left].get_wrong_answers() <= pivot.get_wrong_answers()) {
      left += 1;
    }

    while (candidates[right].get_wrong_answers() > pivot.get_wrong_answers()) {
      right -= 1;
    }

    if (left < right) {
      Candidate aux = candidates[left];
      candidates[left] = candidates[right];
      candidates[right] = aux;
    }
  }

  candidates[pivot_pos] = candidates[right];
  candidates[right] = pivot;

  return right;
}

void Sort::best_candidates(Candidate* candidates, int left, int right) {
  if (left < right) {
    int pivot_position = Sort::partition_best_candidates(candidates, left, right);
    Sort::best_candidates(candidates, left, pivot_position - 1);
    Sort::best_candidates(candidates, pivot_position + 1, right);
  }
}
