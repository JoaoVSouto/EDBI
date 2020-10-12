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

int Sort::partition_worst_candidates(Candidate* candidates, int left, int right) {
  int pivot_pos = left;
  Candidate pivot = candidates[pivot_pos];

  while (left < right) {
    while (candidates[left].get_correct_answers() <= pivot.get_correct_answers()) {
      left += 1;
    }

    while (candidates[right].get_correct_answers() > pivot.get_correct_answers()) {
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

int Sort::partition_questions(Question* questions, int left, int right) {
  int pivot_pos = left;
  Question pivot = questions[pivot_pos];

  while (left < right) {
    while (questions[left].get_number() <= pivot.get_number()) {
      left += 1;
    }

    while (questions[right].get_number() > pivot.get_number()) {
      right -= 1;
    }

    if (left < right) {
      Question aux = questions[left];
      questions[left] = questions[right];
      questions[right] = aux;
    }
  }

  questions[pivot_pos] = questions[right];
  questions[right] = pivot;

  return right;
}

int Sort::partition_best_questions(Question* questions, int left, int right) {
  int pivot_pos = left;
  Question pivot = questions[pivot_pos];

  while (left < right) {
    while (questions[left].get_incorrect_amount() <= pivot.get_incorrect_amount()) {
      left += 1;
    }

    while (questions[right].get_incorrect_amount() > pivot.get_incorrect_amount()) {
      right -= 1;
    }

    if (left < right) {
      Question aux = questions[left];
      questions[left] = questions[right];
      questions[right] = aux;
    }
  }

  questions[pivot_pos] = questions[right];
  questions[right] = pivot;

  return right;
}

int Sort::partition_worst_questions(Question* questions, int left, int right) {
  int pivot_pos = left;
  Question pivot = questions[pivot_pos];

  while (left < right) {
    while (questions[left].get_correct_amount() <= pivot.get_correct_amount()) {
      left += 1;
    }

    while (questions[right].get_correct_amount() > pivot.get_correct_amount()) {
      right -= 1;
    }

    if (left < right) {
      Question aux = questions[left];
      questions[left] = questions[right];
      questions[right] = aux;
    }
  }

  questions[pivot_pos] = questions[right];
  questions[right] = pivot;

  return right;
}

void Sort::best_candidates(Candidate* candidates, int left, int right) {
  if (left < right) {
    int pivot_position = Sort::partition_best_candidates(candidates, left, right);
    Sort::best_candidates(candidates, left, pivot_position - 1);
    Sort::best_candidates(candidates, pivot_position + 1, right);
  }
}

void Sort::worst_candidates(Candidate* candidates, int left, int right) {
  if (left < right) {
    int pivot_position = Sort::partition_worst_candidates(candidates, left, right);
    Sort::worst_candidates(candidates, left, pivot_position - 1);
    Sort::worst_candidates(candidates, pivot_position + 1, right);
  }
}

void Sort::questions(Question* questions, int left, int right) {
  if (left < right) {
    int pivot_position = Sort::partition_questions(questions, left, right);
    Sort::questions(questions, left, pivot_position - 1);
    Sort::questions(questions, pivot_position + 1, right);
  }
}

void Sort::best_questions(Question* questions, int left, int right) {
  if (left < right) {
    int pivot_position = Sort::partition_best_questions(questions, left, right);
    Sort::best_questions(questions, left, pivot_position - 1);
    Sort::best_questions(questions, pivot_position + 1, right);
  }
}

void Sort::worst_questions(Question* questions, int left, int right) {
  if (left < right) {
    int pivot_position = Sort::partition_worst_questions(questions, left, right);
    Sort::worst_questions(questions, left, pivot_position - 1);
    Sort::worst_questions(questions, pivot_position + 1, right);
  }
}
